class Solution {
public:
    int maxPathSumHelper(TreeNode* root, int& res) {
        // base case
        if(root == nullptr) return 0;

        // hypothesis
        int left = maxPathSumHelper(root->left, res);
        int right = maxPathSumHelper(root->right, res);

        // induction
        int temp = max(root->val + max(left, right), root->val);
        int ans = max(temp, root->val + left + right);

        res = max(res, ans);

        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }
};