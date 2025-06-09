class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& values, int i, int j) {
        // base case
        if(j - i < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minVal = 1e9;
        for(int k = i + 1; k < j; k++) {
            int temp = values[i] * values[k] * values[j] + 
                       solve(values, i, k) + 
                       solve(values, k, j);

            minVal = min(minVal, temp);            
        }
        return dp[i][j] = minVal;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(values, 0, n - 1);
    }
};