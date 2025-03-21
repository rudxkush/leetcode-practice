class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;
        for(const auto& x : accounts) {
            int sum = 0;
            for(int y : x) {
                sum += y;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};