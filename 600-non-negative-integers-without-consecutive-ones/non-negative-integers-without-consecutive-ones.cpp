class Solution {
public:
    int findIntegers(int num) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;

        // Precompute Fibonacci-like DP table for valid sequences
        for (int i = 2; i < 32; i++)
            f[i] = f[i - 1] + f[i - 2];

        int res = 0;
        int prev_bit = 0;

        for (int i = 30; i >= 0; i--) {
            if ((num & (1 << i)) != 0) {
                res += f[i];

                if (prev_bit == 1) {
                    return res; // Two consecutive 1s: stop here
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }

        return res + 1; // Include `num` itself if it has no consecutive 1s
    }
};
