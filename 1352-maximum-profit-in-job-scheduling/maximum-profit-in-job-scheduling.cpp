class Solution {
public:
    int m = 0;
    vector<int> dp;
    int solve(vector<tuple<int, int, int>>& jobs, int i) {
        // base case
        if(i == m) return 0;
        if(dp[i] != -1) return dp[i];

        int low = i + 1, high = m - 1, nextJob = m;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(get<0>(jobs[mid]) >= get<1>(jobs[i])) {
                nextJob = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        int take = get<2>(jobs[i]) + solve(jobs, nextJob);
        int notTake = solve(jobs, i + 1);
        return dp[i] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs(n);
        for(int i = 0; i < n; i++) 
            jobs[i] = {startTime[i], endTime[i], profit[i]};  
        m = n; 
        dp.assign(n, -1);
        sort(jobs.begin(), jobs.end());
        return solve(jobs, 0); 
    }
};