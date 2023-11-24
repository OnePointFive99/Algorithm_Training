v1.0: 迭代法，取每一行最后一个即可，注意不能舍弃左子树
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i< size; i++)
            {
                TreeNode *cur = q.front();
                if(i==size-1)result.push_back(cur->val);
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
        }
        return result;
    }
};

v2.0:递归法
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
    void traversal(vector<vector<int>> &treeNodes, TreeNode* cur, int depth)
    {
        if(cur==nullptr)return;
        if(treeNodes.size()==depth)treeNodes.push_back(vector<int>());
        treeNodes[depth].push_back(cur->val);
        traversal(treeNodes, cur->left, depth+1);
        traversal(treeNodes, cur->right, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> treeNodes;
        if(root==nullptr)return result;
        int depth = 0;
        traversal(treeNodes, root, depth);
        for(auto v:treeNodes)
        {
            result.push_back(v[v.size()-1]);
        }
        return result;
    }
};