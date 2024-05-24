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

void traversal(TreeNode* cur, bool isLeft)
{
    if (!cur)
        return;

    if (isLeft && !cur->left && !cur->right)
    {
        ret += cur->val;
        return;
    }
    
    traversal(cur->left, true);
    traversal(cur->right, false);
         
    return;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
        return 0;

    traversal(root, false);
    return ret;
}
};