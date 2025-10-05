class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> res;

        if (!root) return res;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first, row = pos.second;

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        for (auto &p : nodes) {
            vector<int> colVals;
            for (auto &r : p.second) {
                colVals.insert(colVals.end(), r.second.begin(), r.second.end());
            }
            res.push_back(colVals);
        }

        return res;
    }
};
