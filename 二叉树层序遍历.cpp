
v1.0:迭代法  核心思路是每层统计队列大小，按这个大小pop，然后push子节点
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            TreeNode * cur;
            while(size--)
            {
                cur = q.front();
                tmp.push_back(cur->val);
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            result.push_back(tmp);
        }
        return result;
    }
};

v2.0：递归法  是使用数组表示的树，使用depth来做数组第一维度的下标
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
    void traversal(vector<vector<int>> &ret, TreeNode*cur, int depth)
    {
        if(cur==nullptr)return;
        if(ret.size()==depth)ret.push_back(vector<int>());
        ret[depth].push_back(cur->val);

        traversal(ret, cur->left, depth+1);
        traversal(ret, cur->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)return result;
        int depth = 0;
        traversal(result, root, depth);
        return result;
    }
};