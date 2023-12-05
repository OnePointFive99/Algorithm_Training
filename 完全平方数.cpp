class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;
        for(int k = 1; k <= n;k++)
        {
            for(int i = 0; i * i <= k; i++)
            {
                dp[k] = min(dp[k-i * i]+1, dp[k]);
            }
        }
        return dp[n];
    }
};