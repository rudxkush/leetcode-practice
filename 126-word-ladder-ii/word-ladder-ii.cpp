class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string begin;
    void dfs(string word, vector<string>& sequence) {
        if (word == begin) {
            reverse(sequence.begin(), sequence.end());
            ans.push_back(sequence);
            reverse(sequence.begin(), sequence.end());
            return;
        }
        int steps = mp[word];
        for (int i = 0; i < word.length(); i++) {
            char original = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = (j + 'a');
                if (mp.find(word) != mp.end()
                && mp[word] + 1 == steps) {
                    sequence.push_back(word);
                    dfs(word, sequence);
                    sequence.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        begin = beginWord;
        // bfs for finding out the shorted path
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if(word == endWord) {
                break;
            }

            for (int i = 0; i < word.length(); i++) {
                char original = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = (j + 'a');
                    if (st.find(word) != st.end()) {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        // dfs to generate all the sequence that are of the same length
        if (mp.find(endWord) != mp.end()) {
            vector<string> sequence;
            sequence.push_back(endWord);
            dfs(endWord, sequence);
        }
        return ans;
    }
};