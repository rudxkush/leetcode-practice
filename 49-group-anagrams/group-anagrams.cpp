class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wordMap;
        for(string word : strs) {
            string original = word;
            sort(word.begin(), word.end());
            wordMap[word].push_back(original);
        }
        vector<vector<string>> ans;
        for(auto it : wordMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};