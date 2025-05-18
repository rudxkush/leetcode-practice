class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // [2, 3]
        // [5, 4]
        // [6, 4]
        // [6, 7]
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        vector<int> dp;
        for (auto env : envelopes) {
            int currEle = env[1];
            if (dp.empty() || currEle > dp.back()) {
                dp.push_back(currEle); 
            } else {
                auto it = lower_bound(dp.begin(), dp.end(), currEle);
                *it = currEle;
            }
        }
        return dp.size();
    }
};