class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& stoneValue, int i, bool isAliceTurn) {
        if (i >= n) return 0;

        if (dp[i][isAliceTurn] != INT_MIN) return dp[i][isAliceTurn];

        int result = isAliceTurn ? INT_MIN : INT_MAX;
        int currentSum = 0;

        for (int k = 1; k <= 3; ++k) {
            if (i + k - 1 >= n) break;  // prevent out-of-bounds
            currentSum += stoneValue[i + k - 1];

            if (isAliceTurn) {
                result = max(result, currentSum + solve(stoneValue, i + k, false));
            } else {
                result = min(result, solve(stoneValue, i + k, true));
            }
        }

        return dp[i][isAliceTurn] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp = vector<vector<int>>(n + 1, vector<int>(2, INT_MIN));

        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int aliceScore = solve(stoneValue, 0, true);
        int bobScore = total - aliceScore;

        if (aliceScore > bobScore) return "Alice";
        else if (aliceScore < bobScore) return "Bob";
        else return "Tie";
    }
};
