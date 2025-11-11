class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> diffA;
        for (auto it : segments) {
            int start = it[0];
            int end = it[1];
            int colorValue = it[2];
            diffA[start] = (long long) diffA[start] + colorValue;
            diffA[end] = (long long) diffA[end] + (-1*colorValue);
        }
        
        vector<vector<long long>> ans;

        long long prev = -1;
        long long mixColor = 0;

        for (auto &[curr, color] : diffA) {
            if (prev != -1 && mixColor > 0) ans.push_back({prev, curr, mixColor});
            mixColor += color;
            prev = curr;
        }
        return ans;
    }
};