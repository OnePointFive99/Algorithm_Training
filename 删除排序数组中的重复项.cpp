双指针法即可，注意考虑特殊情况，这种升序数组就考虑元素全相同的情况
v1.0
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int slow = 0;
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[slow++] = nums[i];
                if(i==nums.size()-2){
                    nums[slow++] = nums[nums.size()-1];
                }
            }
            else{
                if(i==nums.size()-2){
                    nums[slow++] = nums[nums.size()-1];
                }
            }
        }
       
        return slow;


    }
};