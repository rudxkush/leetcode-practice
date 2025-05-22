class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size(); 
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                int mini = 1e9;

                for(int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1] +
                               dp[i][k - 1] + dp[k + 1][j];
                    
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
