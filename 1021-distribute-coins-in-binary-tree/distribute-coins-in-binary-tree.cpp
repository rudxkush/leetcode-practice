/*
Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
post-order traversal and propagating the 
coinValueRootedAtu upwards
and counting every propagation upwards in tree while performing dfs
 */
class Solution {
public:
    int movesDoneSoFar = 0;
    int rec(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = rec(root->left);
        int right = rec(root->right);

        movesDoneSoFar += abs(left) + abs(right);

        return root->val - 1 + left + right;
    }
    int distributeCoins(TreeNode* root){
        rec(root);
        return movesDoneSoFar;
    }
};