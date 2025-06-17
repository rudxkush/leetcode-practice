class Solution {
public:
    long long solve(int i, int m, vector<vector<int>>& rides, vector<long long>& dp){
        if(i >= m) return 0;
        if(dp[i] != -1) return dp[i];

        long long cost = rides[i][1] - rides[i][0] + rides[i][2];

        int low = i + 1, high = m - 1, nextIdx = m;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(rides[mid][0] >= rides[i][1]){
                nextIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long long take = cost + solve(nextIdx, m, rides, dp);
        long long notTake = solve(i + 1, m, rides, dp);

        return dp[i] = max(take, notTake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        vector<long long> dp(m, -1);
        return solve(0, m, rides, dp);
    }
};
