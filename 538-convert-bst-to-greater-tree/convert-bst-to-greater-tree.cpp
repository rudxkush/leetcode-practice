class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        // reverse Infix Traversal
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int sum = 0;
        while (true) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->right;
            } else {
                if (st.empty())
                    break;
                curr = st.top();
                st.pop();
                sum += curr->val;
                curr->val = sum;

                curr = curr->left;
            }
        }
        return root;
    }
};