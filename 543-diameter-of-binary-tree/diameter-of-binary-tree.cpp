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
    int findMax(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;

        int left = findMax(root->left, maxi);

        int right = findMax(root->right, maxi);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        findMax(root, maxi);
        return maxi;
    }
};