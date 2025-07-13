class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = s.length();
        int i = 0, j = 0;

        while (j < n) {
            // Expand j while s[i] == s[j]
            while (j < n && s[i] == s[j]) {
                ans += (j - i + 1);
                ans %= MOD;
                j++;
            }
            // Move i to j when characters differ
            i = j;
        }

        return (int)ans;
    }
};
