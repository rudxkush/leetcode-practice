class Solution {
public:
    int n = 0;
    int count = 0;
    int expandAcc_lengthType(string& s, int i, int j) {
        while(j < n && i >= 0 && s[i] == s[j]) {
            count++, i--, j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        n = s.length();
        for(int i = 0; i < n; i++) {
            expandAcc_lengthType(s, i, i);
            expandAcc_lengthType(s, i, i + 1);
        }
        return count;
    }
};