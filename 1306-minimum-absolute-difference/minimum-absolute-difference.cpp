class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = (int) arr.size();
        vector<vector<int>> ans;
        int minDiff = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            minDiff = min(diff, minDiff);
        }
        int edgeDiff = arr[n - 1] - arr[n - 2];
        minDiff = min(edgeDiff, minDiff);
        for(int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if(diff == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};