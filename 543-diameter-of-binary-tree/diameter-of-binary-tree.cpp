class Solution {
public:
    int diameterOfBinaryTreeHelper(TreeNode* root, int& res) {
        // base case
        if(root == nullptr) return 0;

        // hypothesis
        int left = diameterOfBinaryTreeHelper(root->left, res);
        int right = diameterOfBinaryTreeHelper(root->right, res);

        // induction
        int temp = max(left, right) + 1; 
        // left or right which is the longest + 1 (currNode as a part of either left or right)

        int ans = max(temp, left + right + 1); // w/o or w the root, choose the maximum answer

        res = max(res, ans);

        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int res = 0;
        int NodeCnt = diameterOfBinaryTreeHelper(root, res); 
        return res - 1;  // as they have asked the number of edges
    }
};