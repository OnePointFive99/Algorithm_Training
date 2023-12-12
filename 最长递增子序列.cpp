/*
1.Fk:长度为k的序列的最长严格递增子序列
2.F0 = 0, F1 = 1, if(max[子序列]<i+1, 子序列.insert, dp+1)
3.增大
*/

不用执着于Fn为最终解
dp[i]一定在的情况下，找最长且满足情况的子序列，最后在所有dp[i]找最大的
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.size()<2)return nums.size();
        for(int i = 0; i<nums.size();i++)
        {
            dp[i] = 1;//至少包括自己
            for(int j = 0; j<i;j++)
            {
                if(nums[i]>nums[j])
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};