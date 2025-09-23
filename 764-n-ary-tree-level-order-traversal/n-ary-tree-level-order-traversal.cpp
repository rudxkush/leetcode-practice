class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> bfs;
        if (!root) return bfs;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            while(size) {
                Node* node = q.front(); q.pop();
                level.push_back(node->val);
                for(auto child : node->children) {
                    q.push(child);
                } 
                size--;
            }
            bfs.push_back(level);
        }
        return bfs;
    }
};
/*
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