class Solution {
public:
    string expandFromCenter(string& s, int i, int j) {
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string maxSizeString = "";
        for(int i = 0; i < n; i++) {
            string oddLenString = expandFromCenter(s, i, i);
            string evenLenString = expandFromCenter(s, i, i + 1);

            if(maxSizeString.length() < oddLenString.length()) {
                maxSizeString = oddLenString;
            }
            if(maxSizeString.length() < evenLenString.length()) {
                maxSizeString = evenLenString;
            }
        }
        return maxSizeString;
    }
};