class Solution {
public:
    vector<vector<int>> dp;
    int mvHelper(vector<vector<int>>& events, int k, int i) {
        if(i == events.size() || k == 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int low = i + 1, high = events.size() - 1, nextIndex =  events.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            if(events[mid][0] > events[i][1]) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int take = events[i][2] + mvHelper(events, k - 1, nextIndex);
        int notTake = mvHelper(events, k, i + 1);

        return dp[i][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); 
        dp.assign(events.size(), vector<int>(k + 1, -1));
        return mvHelper(events, k, 0);
    }
};