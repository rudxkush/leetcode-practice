class Solution {
public:
    unordered_map<int, bool> memo;
    bool fn(string& s, vector<string>& wordDict, int i) {
        // base case
        if(i == s.size()) {
            return true;
        }
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }
        // choices
        for(int j = 0; j < wordDict.size(); j++) {
            if(s.substr(i, wordDict[j].size()) != wordDict[j]) { // validating choice 
                continue;
            }
            if (fn(s, wordDict, i + wordDict[j].size())) { // move forward ->
                return memo[i] = true;
            }
        }
        return memo[i] = false; // backtrack
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string ans;
        return fn(s, wordDict, 0);
    }
};
