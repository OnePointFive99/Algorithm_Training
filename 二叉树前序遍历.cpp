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
    void traversal(vector<int> &ret, TreeNode *cur)
    {
        if(cur==nullptr)return;
        ret.push_back(cur->val);
        traversal(ret, cur->left);
        traversal(ret, cur->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur = root;
        traversal(result, cur);
        return result;
    }
};