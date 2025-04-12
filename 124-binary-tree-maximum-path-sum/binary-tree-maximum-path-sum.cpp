class Solution {
public:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node)
            return 0;

        int leftSum = max(0, dfs(node->left, maxSum));
        int rightSum = max(0, dfs(node->right, maxSum));

        maxSum = max(maxSum, leftSum + rightSum + node->val);
        
        return max(leftSum, rightSum) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        dfs(root, maxSum);
        return maxSum;
    }
};