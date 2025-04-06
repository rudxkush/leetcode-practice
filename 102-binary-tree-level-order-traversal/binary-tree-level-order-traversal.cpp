class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> TreeQueue;
        TreeQueue.push(root);

        while (!TreeQueue.empty()) {
            vector<int> level;
            int size = TreeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = TreeQueue.front();
                TreeQueue.pop();

                level.push_back(current->val);

                if (current->left != nullptr)
                    TreeQueue.push(current->left);

                if (current->right != nullptr)
                    TreeQueue.push(current->right);
            }
            res.push_back(level);
        }
        return res;
    }
};