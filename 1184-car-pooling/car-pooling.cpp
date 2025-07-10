class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> prefix(1001, 0);
        for(auto trip : trips) {
            prefix[trip[1]] += trip[0];
            prefix[trip[2]] -= trip[0];
        }

        int seated = 0;
        for(int i = 0; i < 1001; i++) {
            seated += prefix[i];
            if(seated > capacity) return false;
        }
        return true;
    }
};