v1.0  递归法  很简单，正常层序遍历之后将result反转即可
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
    void traversal(vector<vector<int>> &result, TreeNode*cur, int depth)
    {
        if(cur==nullptr)return;
        if(depth==result.size())result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        traversal(result, cur->left, depth+1);
        traversal(result, cur->right, depth+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)return result;
        int depth=0;
        traversal(result, root, depth);
        reverse(result.begin(), result.end());
        return result;
    }
};

v2.0 : 迭代法 使用队列 通过队列的尺寸来限制下一次读的次数，注意要保持队列里面不能有空指针
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i <n;i++)
            {
                TreeNode *cur = q.front();
                tmp.push_back(cur->val);
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            result.push_back(tmp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};