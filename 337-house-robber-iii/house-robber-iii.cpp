class Solution {
public:
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
    int solve(TreeNode* root, bool StoleSomethingAlready) {
        // base case
        if (root == nullptr)
            return 0;

        if (dp.count(root) && dp[root].count(StoleSomethingAlready))
            return dp[root][StoleSomethingAlready];

        int steal = 0;
        int notSteal = 0;
        if (!StoleSomethingAlready)
            steal = root->val + solve(root->left, true) + solve(root->right, true);

        notSteal = solve(root->left, false) + solve(root->right, false);

        return dp[root][StoleSomethingAlready] = max(steal, notSteal);
    }
    int rob(TreeNode* root) { 
        return solve(root, false); 
    }
};