class Solution {
public:
    int dfs(TreeNode* root, long long runningSum, int target,
            unordered_map<long long, int>& mp) {
        if (!root)
            return 0;

        runningSum += root->val;
        int count = 0;

        if (mp.count(runningSum - target)) {
            count += mp[runningSum - target];
        }

        mp[runningSum]++;

        count += dfs(root->left, runningSum, target, mp);
        count += dfs(root->right, runningSum, target, mp);

        mp[runningSum]--;

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        return dfs(root, 0, targetSum, mp);
    }
};
