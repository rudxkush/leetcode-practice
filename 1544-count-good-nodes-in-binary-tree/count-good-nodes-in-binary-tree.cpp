class Solution {
public:
    void countGoodNodes(TreeNode* root, int maxSoFar, int& count) {
        if(root == nullptr) return;

        if(root->val >= maxSoFar) {
            count++;
            maxSoFar = root->val; 
        }
        countGoodNodes(root->left, maxSoFar, count);
        countGoodNodes(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        countGoodNodes(root, root->val, count);
        return count;
    }
};
