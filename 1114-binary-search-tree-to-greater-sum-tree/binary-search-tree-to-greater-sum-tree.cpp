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
    void inverseInfixTraversal(TreeNode* root, int& nodeSum) {
        if (!root) {
            return;
        }
        inverseInfixTraversal(root->right, nodeSum);
        nodeSum += root->val;
        root->val = nodeSum;
        inverseInfixTraversal(root->left, nodeSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        // reverse Infix Traversal
        int nodeSum = 0;
        inverseInfixTraversal(root, nodeSum);
        return root;
    }
};