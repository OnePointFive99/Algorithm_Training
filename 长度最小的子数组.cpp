
v1.0：直接暴力：超时 用时14分钟
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> result;
        result.push_back(0);
        for(int left = 0; left < nums.size(); left++){
            int sum = 0, len = 0;
            for(int right = left; right < nums.size(); right++){
                sum+=nums[right];
                len++;
                if(sum >= target){
                    result.push_back(len);
                    break;
                }
            }
        }
        sort(result.begin(), result.end());
        return result.size()>1?result[1]:result[0];
    }
};


v2.0：使用滑动窗口  17分钟（后面11分钟在找bug...）
滑动窗口的思想其实很简单，传统暴力使用两个for循环分别控制窗口的边界
滑动窗口重点在于滑~ 所以其中一个边界是靠条件来操控的
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, len = 0,left = 0;
        vector<int> result;
        result.push_back(0);
        for(int right = 0; right<nums.size();right++){
            sum+=nums[right];
            len++;
            while(sum>=target&&left<nums.size()){
                result.push_back(len);
                sum-=nums[left++];
                len--;
            }
        }
        sort(result.begin(), result.end());
        return result.size()>1?result[1]:result[0];
    }
};


v3.0：
前面使用vector有点大材小用，这里将result声明为INT32_MAX可以直接迭代
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, len = 0,left = 0,result = INT32_MAX;

        for(int right = 0; right<nums.size();right++){
            sum+=nums[right];
            len++;
            while(sum>=target&&left<nums.size()){
                result = len<result?len:result;
                sum-=nums[left++];
                len--;
            }
        }
        return result==INT32_MAX?0:result;
    }
};