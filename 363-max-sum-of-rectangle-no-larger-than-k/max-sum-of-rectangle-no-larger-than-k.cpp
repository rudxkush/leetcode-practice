class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < m; ++left) {
            vector<int> prefix(n, 0);

            for (int right = left; right < m; ++right) {
                for (int row = 0; row < n; ++row) {
                    prefix[row] += matrix[row][right];
                }

                set<int> prefixSums;
                prefixSums.insert(0);
                int currSum = 0;

                for (int val : prefix) {
                    currSum += val;

                    auto it = prefixSums.lower_bound(currSum - k);
                    if (it != prefixSums.end()) {
                        maxSum = max(maxSum, currSum - *it);
                        if (maxSum == k)
                            return k;
                    }
                    prefixSums.insert(currSum);
                }
            }
        }

        return maxSum;
    }
};
