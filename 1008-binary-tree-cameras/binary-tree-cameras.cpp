class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }
    int rec(TreeNode* root, int placeCameraHere, int parentCamera, map<pair<TreeNode*, pair<bool, bool>>, int>& dp) {
        // base case
        if (root == NULL) {
            if (placeCameraHere == 1)
                return 1e9;
            return 0;
        }

        // leaf condition
        if (isLeaf(root)) {
            if (parentCamera == 1) {
                if (placeCameraHere == 1)
                    return 1;
                else
                    return 0;
            } else {
                if (placeCameraHere == 0)
                    return 1e9;
                else
                    return 1;
            }
        }
        
        if(dp.find({root, {placeCameraHere, parentCamera}}) != dp.end()) // If already computed!
            return dp[{root, {placeCameraHere, parentCamera}}];

        // choices : place (or) notPlace
        if (placeCameraHere) {
            /*  If we place a camera at this node:
                1. Add 1 for the current camera.
                2. For each child, recursively decide the minimum cameras needed, 
                   considering that this node now has a camera (parentCamera = 1).
                   Each child can either have a camera or not (place = 0 or 1).  */ 
            return dp[{root, {placeCameraHere, parentCamera}}] = 1 + min(rec(root->left, 0, 1, dp), rec(root->left, 1, 1, dp)) +
                                                                     min(rec(root->right, 0, 1, dp), rec(root->right, 1, 1, dp));
        } else {
            if (parentCamera) {
                /*  If the parent already has a camera:
                    - This node is covered by parent, so it's optional to place a camera here.
                    - Each child can either have a camera or not, choose the minimum for both children.  */
                return dp[{root, {placeCameraHere, parentCamera}}] = min(rec(root->left, 1, 0, dp), rec(root->left, 0, 0, dp)) +
                                                                     min(rec(root->right, 1, 0, dp), rec(root->right, 0, 0, dp));
            } else {
                /*  If the parent does NOT have a camera:
                    - This node is not covered, so we must ensure at least one child has a camera.
                    - Try placing a camera on the left child or the right child (forceLeft / forceRight)
                      and pick the option with the minimum total cameras.   */
                int forceLeft = rec(root->left, 1, 0, dp) +
                    min(rec(root->right, 1, 0, dp), rec(root->right, 0, 0, dp));

                int forceRight = rec(root->right, 1, 0, dp) +
                    min(rec(root->left, 1, 0, dp), rec(root->left, 0, 0, dp));

                return dp[{root, {placeCameraHere, parentCamera}}] = min(forceLeft, forceRight);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        if (root == NULL)
            return 0;
        map<pair<TreeNode*, pair<bool, bool>>, int> dp;
        return min(rec(root, 0, 0, dp), rec(root, 1, 0, dp));
    }
};