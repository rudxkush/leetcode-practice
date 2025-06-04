class Solution {
public:
    bitset<10001> perfectSquare = 0; 
    void precomputePerfectSquares() {
        for(int i = 1; i <= 100; i++) 
            perfectSquare[i * i] = 1;
    }
    int minimumWays(int n, vector<int>& dp) {
        // base case
        if (n == 0)
            return 0;
        if (n < 0)
            return 1e9;
        if (dp[n] != -1)
            return dp[n];

        int ways = 1e9;
        for (int k = 1; k <= n; k++) {
            if(perfectSquare[k]) {
                int temp = 1 + minimumWays(n - k, dp);
                ways = min(temp, ways);
            }
        }
        return dp[n] = ways;
    }
    int numSquares(int n) {
        precomputePerfectSquares();
        vector<int> dp(n + 1, -1);
        int ans = minimumWays(n, dp);
        return ans != 1e9 ? ans : -1;
    }
};

/*

    n = 12 output -> 3
    return the least number of primes square numbers that sum to n
    12 = 4 + 4 + 4

    n = 13 output -> 2
    13 = 4 + 9

*/