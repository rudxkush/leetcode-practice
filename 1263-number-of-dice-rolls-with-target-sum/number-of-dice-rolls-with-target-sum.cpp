class Solution {
public:
    int MOD = (int) 1e9 + 7; 
    int faces = 0;
    vector<vector<int>> dp;
    // return the ways you could sum up to target with the given faces
    int nrtHelper(int n, int target) {
        // base cases
        if(n == 0) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }
        if(target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int count = 0;
        for(int k = 1; k <= faces; k++) {
            if(target - k >= 0) {
                count = (count + nrtHelper(n - 1, target - k)) % MOD;
            }
        }
        return dp[n][target] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
        faces = k;
        dp.resize(n + 1, vector<int>(target + 1, -1));
        return nrtHelper(n, target);
    }
};