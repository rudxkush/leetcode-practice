class Solution {
public:
    vector<int> dp;

    int numDecodingsHelper(string& s, int i) {
        if (i == s.length()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        // k = 1
        int count = numDecodingsHelper(s, i + 1);

        // k = 2
        if (i + 1 < s.size()) {
            int twoDigit = stoi(s.substr(i, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                count += numDecodingsHelper(s, i + 2);
            }
        }

        return dp[i] = count;
    }

    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return numDecodingsHelper(s, 0);
    }
};


/*
s = 226, i = 0

i = 1 as 2 is valid, i = 2 as 22 is also valid

i = 2 as 2 is valid + i = 3 as 26 is valid, i = 3 as 6 is valid

i = 3 as 6 is valid

1 -> 3 -> 3
*/