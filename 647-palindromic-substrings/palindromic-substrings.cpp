class Solution {
public:
    int n = 0;
    int cnt = 0;
    bool isPalindrome(string& ans) {
        int i = 0, j = ans.length() - 1;
        while(i < j) if(ans[i++] != ans[j--]) return false;
        return true;
    }
    void countHelper(string& s, int i, string& ans) {
        // base case
        if(!ans.empty() && isPalindrome(ans)) {
            cnt++;
        }

        for(int choices = i; choices < n; choices++) {
            // choose
            ans.push_back(s[choices]);
            // move forward
            countHelper(s, i + 1, ans);
            // backtrack
            ans.pop_back();
            break; 
        }
    }
    int countSubstrings(string s) {
        n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++) countHelper(s, i, ans);
        return cnt;
    }
};

/*
  a b c
  a
  a b -> Not a palindrome
  a b c -> Not a palindrome
  b 
  b c -> Not a palindrome
  c
  Output => "a", "b", "b" = (?count) 3
*/