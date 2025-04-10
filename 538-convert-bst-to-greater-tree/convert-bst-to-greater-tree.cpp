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
    TreeNode* convertBST(TreeNode* root) {
        // reverse Infix Traversal
        int nodeSum = 0;
        inverseInfixTraversal(root, nodeSum);
        return root;
    }
};