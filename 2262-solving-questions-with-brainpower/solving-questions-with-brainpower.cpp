class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>& questions, int i) {
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];

        long long include = questions[i][0] + solve(questions, i + questions[i][1] + 1);

        long long exclude = solve(questions, i + 1);

        return dp[i] = max(include, exclude);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.assign(questions.size(), -1);
        return solve(questions, 0);
    }
};