class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) {
            return n * m;
        }
        int min_i = INT_MAX;
        int min_j = INT_MAX;
        for (auto it : ops) {
            min_i = min(min_i, it[0]);
            min_j = min(min_j, it[1]);
        }
        return (min_i * min_j);
    }
};