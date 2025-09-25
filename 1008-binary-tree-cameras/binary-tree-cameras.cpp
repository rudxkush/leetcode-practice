class Solution {
public:
    void dfs(TreeNode* node, int& ans) {
        if (!node || (!node->left && !node->right))
            return;

        dfs(node->left, ans);
        dfs(node->right, ans);

        if ((node->left && node->left->val == 0) ||
            (node->right && node->right->val == 0)) {
            node->val = 1;
            ans++;
        } else if (node->left && node->left->val == 1 ||
                   node->right && node->right->val == 1) {
            node->val = 2;
        }
    }

    int minCameraCover(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        ans += root->val == 0;
        return ans;
    }
};