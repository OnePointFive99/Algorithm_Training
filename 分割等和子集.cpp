class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if(sum%2!=0)return false;//和是奇数无法平分
        int target = sum/2;
        if(maxNum>target)return false;//最大的数小于一半才能平分
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for(auto v : dp)
        {
            v[0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = )

    }
};