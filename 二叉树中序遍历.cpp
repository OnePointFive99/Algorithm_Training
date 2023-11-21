
v1.0:注意理解递归的思想，递归就是套娃，递归到叶子节点就会返回
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
        ret.push_back(cur->val);
        traversal(ret, cur->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(result, root);
        return result;
    }
};

v2.0: 迭代 
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)return result;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur||!stk.empty())
        {
            if(cur)
            {
                stk.push(cur);
                cur=cur->left;
            }else{
                cur = stk.top();
                stk.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
            
        }
        return result;
    }
};

v3.0:统一迭代  标记法
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
    vector<int> inorderTraversal(TreeNode* root) {
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
                if(cur->right)stk.push(cur->right);
                stk.push(cur);
                stk.push(nullptr);
                if(cur->left)stk.push(cur->left);
            }else{
                stk.pop();//nullptr
                cur = stk.top();
                stk.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }
};