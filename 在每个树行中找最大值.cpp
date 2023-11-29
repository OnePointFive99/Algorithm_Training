v1.0:递归法 注意int的最小值：INT_MIN -2147483648
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(vector<vector<int>> &treeNodes, TreeNode *cur, int depth)
    {
        if(cur==nullptr)return;
        if(treeNodes.size()==depth)treeNodes.push_back(vector<int>());
        treeNodes[depth].push_back(cur->val);
        traversal(treeNodes, cur->left, depth+1);
        traversal(treeNodes, cur->right, depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> treeNodes;
        if(root==nullptr)return vector<int>();
        int depth = 0;
        traversal(treeNodes, root, depth);
        vector<int> result(treeNodes.size(), INT_MIN);
        for(int i = 0; i <treeNodes.size();i++)
        {
            for(auto e:treeNodes[i])
            {
                if(e>result[i])result[i]=e;
            }
        }
        return result;
    }
};