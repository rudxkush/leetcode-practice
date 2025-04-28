class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        // bfs
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int hops = q.front().second;
            q.pop();
            if (word == endWord) {
                return hops;
            }

            for (int i = 0; i < word.length(); i++) {
                char original = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = (j + 'a');
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, hops + 1});
                    }
                    word[i] = original;
                }
            }
        }
        return 0;
    }
};