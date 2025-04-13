class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(postorder, 0, postorder.size() - 1,
                               inorder, 0, inorder.size() - 1,
                               inMap);
    }
    TreeNode* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int, int>& inMap) {
                                
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1,
                                     inorder, inStart, inRoot - 1,
                                     inMap);

        root->right =  buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1,
                                       inorder, inRoot + 1, inEnd,
                                       inMap);

        return root;
    }
};