class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }

    void fn(string& s, int start, string& current, int& count) {
        // At each step, check if current substring is a palindrome
        if (!current.empty() && isPalindrome(current)) {
            count++;
        }

        // Try to extend the substring to the right
        for (int i = start; i < s.length(); ++i) {
            current.push_back(s[i]);
            fn(s, i + 1, current, count); // move start forward
            current.pop_back(); // backtrack
            break; // Ensure only contiguous characters (i.e., break after extending once)
        }
    }

    int countSubstrings(string s) {
        int count = 0;
        string current = "";
        for (int i = 0; i < s.length(); ++i) {
            fn(s, i, current, count);
        }
        return count;
    }
};
