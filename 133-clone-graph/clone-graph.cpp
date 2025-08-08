class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& nodeMap) {
        if(nodeMap.find(node) != nodeMap.end()) {
            return nodeMap[node];
        }

        Node* cloneNode = new Node(node->val);
        for(Node* iterator : node->neighbors) {
            nodeMap[node] = cloneNode;
            cloneNode->neighbors.push_back(dfs(iterator, nodeMap));
        }
        return cloneNode;
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodeMap;
        return dfs(node, nodeMap);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
