做完乘积最大子数组之后这道题就秒了
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> MaxF(nums);
        for(int i = 1; i<nums.size(); i++)
        {
            MaxF[i] = max(MaxF[i-1] + nums[i], nums[i]);
        }
        return *max_element(MaxF.begin(), MaxF.end());
    }
};