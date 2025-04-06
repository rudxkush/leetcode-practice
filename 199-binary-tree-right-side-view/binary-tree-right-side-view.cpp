class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> TreeQueue;
        TreeQueue.push(root);

        while (!TreeQueue.empty()) {
            int size = TreeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = TreeQueue.front();
                TreeQueue.pop();

                if (i == (size - 1))
                    res.push_back(current->val);

                if (current->left != NULL)
                    TreeQueue.push(current->left);

                if (current->right != NULL)
                    TreeQueue.push(current->right);
            }
        }
        return res;
    }
};