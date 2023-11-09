v1.0:直接暴力  4分半做出来，用sort  api
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i<nums.size();i++){
            result.push_back(nums[i]*nums[i]);
        }
        sort(result.begin(), result.end());
        return result;


    }
};

v2.0:  13分钟
看过题解之后的做法，使用双指针，从原数组两端收缩，比较平方值大小，放入创建的新数组中
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int begin = 0, end = nums.size()-1, i = nums.size()-1;
        vector<int> result(nums.size(), 0);
        while(begin<=end){
            if(nums[end]*nums[end]>=nums[begin]*nums[begin]){
                result[i--] = nums[end]*nums[end];
                end--;
            }
            else{
                result[i--] = nums[begin]*nums[begin];
                begin++;
            }
        }
        return result;
    }
};