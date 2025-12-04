class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(long long base, long long x) {
        long long res = 1;
        while (x > 0) {
            if (x%2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            x /= 2;
        }
        return res;
    }
    int modInverse(int num, int M) { 
        return power(num, M - 2); 
    }
    int makeStringSorted(string s) {
        int n = s.length();
        long long rank = 0;
        int freq[26] = {0};

        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            long long smaller_count = 0;
            for (int j = 0; j < s[i] - 'a'; j++) {
                smaller_count += freq[j];
            }

            long long denominator = 1;
            for (int k = 0; k < 26; k++) {
                denominator = (denominator * fact[freq[k]]) % mod;
            }

            long long permutation_count =
                (fact[n - 1 - i] * modInverse(denominator, mod)) % mod;

            rank = (rank + smaller_count * permutation_count) % mod;

            freq[s[i] - 'a']--;
        }
        return (int) rank;
    }
};