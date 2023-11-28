v1.0:迭代法 一遍过~
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> treeNodes;
        if(root==nullptr)return treeNodes;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty())
        {
            int size = q.size();
            treeNodes.push_back(vector<int>());
            for(int i = 0; i< size; i++)
            {
                Node* cur = q.front();
                q.pop();
                treeNodes[depth].push_back(cur->val);
                for(auto c:cur->children)
                {
                    q.push(c);
                }
            }
            depth++;            
        }
        return treeNodes;
    }
};