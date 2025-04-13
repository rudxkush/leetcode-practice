class Solution {
public:
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int start, int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[start]);

        int i;
        for (i = start + 1; i <= end; i++) {
            if (preorder[i] > root->val) {
                break;
            }
        }

        root->left = bstFromPreorderHelper(preorder, start + 1, i - 1);
        root->right = bstFromPreorderHelper(preorder, i, end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start = 0;
        int end = preorder.size() - 1;
        return bstFromPreorderHelper(preorder, start, end);
    }
};