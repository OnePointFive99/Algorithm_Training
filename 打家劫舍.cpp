v1.0:动态规划入门第一题：定义子问题、子问题递推公式、确定dp数组计算方向
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

v2.0:第一次尝试空间优化 成功！ 感觉区别在于：要把pre和cur映射到dp数组中的位置，但是i不用从0开始
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int curr = 0, prer = 0;
        for(int i = 0; i < n;i++)
        {
            int tmp = curr;
            curr = max(prer + nums[i], tmp);
            prer = tmp;
        }
        return curr;
    }
};