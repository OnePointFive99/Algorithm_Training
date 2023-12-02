v1.0:递归法
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
    int min_depth = INT_MAX;
    void traversal(vector<vector<TreeNode*>>& treeNodes, TreeNode* cur, int depth)
    {
        if(cur==nullptr)return;
        if(treeNodes.size()==depth)treeNodes.push_back(vector<TreeNode*>());
        treeNodes[depth].push_back(cur);
        if(cur->left==nullptr && cur->right==nullptr &&depth<min_depth)min_depth = depth+1;
        traversal(treeNodes, cur->left, depth+1);
        traversal(treeNodes, cur->right, depth+1);
    }

    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        vector<vector<TreeNode*>> treeNodes;
        int depth = 0;
        traversal(treeNodes, root, depth);
        return min_depth;
    }
};