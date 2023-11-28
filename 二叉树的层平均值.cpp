
v1.0 : 递归法 得到treeNodes后 再对treeNodes的每个元素取均值
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
    void traversal(vector<vector<int>> &treeNodes, TreeNode * cur, int depth)
    {
        if(cur==nullptr)return;
        if(treeNodes.size()==depth)treeNodes.push_back(vector<int>());
        treeNodes[depth].push_back(cur->val);
        traversal(treeNodes, cur->left, depth + 1);
        traversal(treeNodes, cur->right, depth + 1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root==nullptr)return result;
        int depth = 0;
        vector<vector<int>> treeNodes;
        traversal(treeNodes, root, depth);
        for(auto v:treeNodes)
        {
            double sum = 0;
            double count = 0;
            for(int i:v)
            {
                sum += i;
                count++;
            }
            result.push_back(sum / count);
        }
        return result;
        
    }
};

v2.0: 迭代法
