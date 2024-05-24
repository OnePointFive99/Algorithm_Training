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
    vector<string> ret;
void traversal(TreeNode* cur, string s)
{
    if (!cur->left && !cur->right)
    {
        ret.emplace_back(s);
        return;
    }
    string tmp = s;
    if (cur->left)
    {
        traversal(cur->left, s.append("->" + to_string(cur->left->val)));
    }
    s = tmp;
    if (cur->right)
    {
        traversal(cur->right, s.append("->" + to_string(cur->right->val)));
    }
         
    return;
}

vector<string> binaryTreePaths(TreeNode* root) {
    
    if (root == nullptr)
        return ret;
    string start = to_string(root->val);
    traversal(root, start);
    return ret;
}
};