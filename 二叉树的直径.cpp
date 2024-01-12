这道题主要是一个深度优先搜索的思路，重点要明确的思路是某点的路径的最大节点数是左子树最大深度+右子树最大深度+1
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
    int ret;
    int dfs(TreeNode* root)
    {
        if(root = nullptr)return ret;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ret = max(ret, l + f + 1);
        return max(L, R) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==nullptr)return 0;
        ret = 1;
        dfs(root);
        return ret - 1;//节点数-1是路径
    }
};