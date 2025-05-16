class Solution {
public:
    vector<string> validList;
    void wordBreak(string& s, int i, string ans,
                   unordered_set<string>& wordSet) {
        // base case
        if (i == s.size()) {
            validList.push_back(ans);
            return;
        }
        // choices
        for (const string& word : wordSet) {
            // choose
            int len = word.length();
            if (i + len > s.length())
                continue; // overflow condn
            string str = s.substr(i, len);
            if (str != word)
                continue;
            // move forward
            string prev = ans;
            if (ans == "") {
                ans += word;
            } else {
                ans += " " + word;
            }
            wordBreak(s, i + len, ans, wordSet);
            // backtrack
            ans = prev;
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        wordBreak(s, 0, "", wordSet);
        return validList;
    }
};