
v1.0:递归法：
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
        traversal(result, root);
        return result;
    }
};

v2.0:迭代法：建立一个装树的节点的栈，然后更新栈时把夫节点取出，放入子节点即可
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode * cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            if(cur->right)stk.push(cur->right);
            if(cur->left)stk.push(cur->left);
        }
        return result;
    }
};