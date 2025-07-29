class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> storeParents;

    void dfsTraversal(TreeNode* root, TreeNode* parent) {
        if (root == nullptr)
            return;
        storeParents[root] = parent;
        dfsTraversal(root->left, root);
        dfsTraversal(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfsTraversal(root, nullptr);

        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> visited;
        vector<int> res;

        q.push({target, 0});
        visited.insert(target);

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (steps == k) {
                res.push_back(node->val);
                continue;  // Don't explore further from this node
            }

            for (TreeNode* neighbor : {node->left, node->right, storeParents[node]}) {
                if (neighbor && visited.find(neighbor) == visited.end()) {
                    q.push({neighbor, steps + 1});
                    visited.insert(neighbor);
                }
            }
        }

        return res;
    }
};
