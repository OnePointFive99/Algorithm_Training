/*
1. Fn nums的乘积最大子数组  Fk nums的k子集的乘积最大子数组
2. */
v1.0:超时
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int32_t> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = dp[i-1];
            for(int j = 0; j<=i;j++)
            {
                int mul = 1;
                for(int k = i; k>=j; k--)
                {
                    mul *= nums[k];
                }
                dp[i] = max(dp[i], mul);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

其实这个题一直在纠结到底前面不要的怎么处理，自己用例子试了一下发现
其实只有前面是负的才会不要，这时候可以用max(f(i-1), nums[i])来筛选掉
这道题实现简单，思路略难
v2.0:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> MaxF(nums), MinF(nums);
        for(int i = 1; i < nums.size(); i++)
        {
            MaxF[i] = max(MaxF[i-1] * nums[i], max(MinF[i-1] * nums[i], nums[i]));
            MinF[i] = min(MaxF[i-1] * nums[i], min(MinF[i-1] * nums[i], nums[i]));
        }
        return *max_element(MaxF.begin(), MaxF.end());
    }
};

