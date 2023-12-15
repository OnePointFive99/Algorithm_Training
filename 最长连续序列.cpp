class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1, ret = 0;
        if(nums.size()==0)return ret;
        if(nums.size()==1)return count;
        for(int i = 0; i<nums.size()-1;i++)
        {
            
            if(nums[i+1]==nums[i]+1){
                count++;
                if(i+1==nums.size()-1)
                {
                    ret = count>ret?count:ret;
                }
            }else if(nums[i+1]==nums[i])
            {
                if(i+1==nums.size()-1)
                {
                    ret = count>ret?count:ret;
                }
            }else{
                ret = count>ret?count:ret;
                count=1;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto x:nums)hash.insert(x);
        int ret = 0;
        for(auto x:hash)
        {
            if(!hash.count(x-1))//不存在前置连续数字
            {
                int t = x;
                while(hash.count(t+1))
                {
                    t++;
                }
                ret = max(t-x+1, ret);
            }
        }
        return ret;
    }
};
