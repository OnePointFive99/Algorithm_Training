v1.0: 递归法
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
        traversal(ret, cur->left);
        traversal(ret, cur->right);
        ret.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(result, root);
        return result;
    }
};

v2.0: 迭代法 因为后续遍历时右左中 把前序遍历变成中右左，最后再反转一下就行了
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            if(cur->left)stk.push(cur->left);
            if(cur->right)stk.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;

    }
};


v3.0: 统一迭代法  后序遍历 标记法
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *cur = stk.top();
            if(cur!=nullptr)
            {
                stk.pop();
                stk.push(cur);
                stk.push(nullptr);
                if(cur->right)stk.push(cur->right);
                if(cur->left)stk.push(cur->left);
            }else{
                stk.pop();
                cur = stk.top();
                stk.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }
};