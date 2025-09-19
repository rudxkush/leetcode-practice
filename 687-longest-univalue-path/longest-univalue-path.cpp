/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = 0, rightPath = 0;
        if (root->left != NULL && root->left->val == root->val) {
            leftPath = left;
        }
        if (root->right != NULL && root->right->val == root->val) {
            rightPath = right;
        }

        res = max(res, 1 + leftPath + rightPath);

        return 1 + max(leftPath, rightPath);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        return res - 1;
    }
};