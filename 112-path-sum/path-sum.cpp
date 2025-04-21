class Solution {
public:
    bool dfs(TreeNode* root, int targetSum, int sum) {
        // base case
        if (root == nullptr)
            return false;

        sum += root->val;

        if (root->left == nullptr && root->right == nullptr)
            return sum == targetSum;

        return dfs(root->left, targetSum, sum) ||
               dfs(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return dfs(root, targetSum, 0);
    }
};