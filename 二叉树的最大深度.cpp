v1.0:迭代法
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
    int maxDepth(TreeNode* root) {
    int max_depth = 0;
    if(root==nullptr)return max_depth;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        if(size > 0)max_depth++;
        for(int i = 0; i < size; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
    }
    return max_depth;
    }
};