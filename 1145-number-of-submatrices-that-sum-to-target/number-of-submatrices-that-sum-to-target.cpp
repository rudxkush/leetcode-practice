class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        for (int L = 0; L < m; L++) {
            vector<int> prefix(n, 0);
            for (int R = L; R < m; R++) {
                for (int r = 0; r < n; r++) {
                    prefix[r] += matrix[r][R];
                }

                // Here comes the same logic we used to solve Max Sum of
                // Rectangle No Larger Than K
                /*
                            it comes down to 1D array and now we can use
                   interval logic to get the desired output. 1 3 5 6 2

                            prefix - X where X is the minimum among all the
                   candidates

                            prefix - X == target
                */

                unordered_map<int, int> map;
                map[0] = 1;
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += prefix[i];
                    if (map.count(sum - target)) {
                        count += map[sum - target];
                    }
                    map[sum]++;
                }
            }
        }
        return count;
    }
};