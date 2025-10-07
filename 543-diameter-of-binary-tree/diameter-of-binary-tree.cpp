/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rec(TreeNode* root, int& res) {
        if(root == NULL)
            return 0;

        int left = rec(root->left, res);
        int right = rec(root->right, res);

        int temp = 1 + max(left, right);
        int ans = 1 + left + right;
        res = max({res, temp, ans});
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 1;
        rec(root, res);
        return res - 1;
    }
};