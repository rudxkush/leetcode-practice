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
    int i = 0;
    vector<int> flippedNodesP;
    bool helper(TreeNode* root, vector<int>& voyage) {
        if(root == NULL) return true;

        if(root->val != voyage[i]) return false;
        i++;

        if(root->left && root->left->val != voyage[i]) {
            flippedNodesP.push_back(root->val);
            swap(root->left, root->right);
        }
        return helper(root->left, voyage) && helper(root->right, voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        i = 0;
        if(helper(root, voyage)) return flippedNodesP;
        return {-1};
    }
};