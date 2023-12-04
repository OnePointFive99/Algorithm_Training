
v1.0:回溯法第一题！重点是画出树，然后递归，递归注意需要传的条件，然后记得写终结条件、记得撤销更改
class Solution {
public:
    void traversal(vector<vector<int>>& result, vector<int>& nums, int depth, int n)
    {
        if(depth==n)//到达叶子节点,默认满足条件
        {
            result.push_back(nums);
            return;
        }
        for(int i = depth; i < n; i++)
        {
            swap(nums[i], nums[depth]);
            traversal(result, nums, depth+1, n);
            swap(nums[i], nums[depth]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> result;//n根树枝
        int depth = 0;
        traversal(result, nums, depth, n);
        return result;
    }
};