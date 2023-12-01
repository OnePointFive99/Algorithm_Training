v1.0:递归法
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traversal(Node* cur, vector<vector<Node*>>& treeNodes, int depth)
    {
        if(cur==nullptr)return;
        if(treeNodes.size()==depth)treeNodes.push_back(vector<Node*>());
        treeNodes[depth].push_back(cur);
        traversal(cur->left, treeNodes, depth+1);
        traversal(cur->right, treeNodes, depth+1);
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> treeNodes;
        if(root==nullptr)return root;
        int depth = 0;
        traversal(root, treeNodes, depth); 
        for(int i = 0; i < treeNodes.size();i++)
        {
            for(int j = 0; j < treeNodes[i].size()-1;j++)
            {
                treeNodes[i][j]->next = treeNodes[i][j+1];
            }
        }
        return root;
    }
};