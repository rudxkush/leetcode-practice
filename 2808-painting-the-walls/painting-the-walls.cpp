class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int wallsLeft, vector<int>& cost, vector<int>& time) {
        // no walls left to paint
        if (wallsLeft <= 0) return 0; 
        // out of walls, not valid
        if (i >= cost.size()) return 1e9; 
        // if already computed
        if (dp[i][wallsLeft] != -1) return dp[i][wallsLeft];

        // Option 1: don't hire this painter
        int skip = solve(i + 1, wallsLeft, cost, time);

        // Option 2: hire this painter
        int take = cost[i] + solve(i + 1, wallsLeft - 1 - time[i], cost, time);

        return dp[i][wallsLeft] = min(skip, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, n, cost, time);
    }
};
