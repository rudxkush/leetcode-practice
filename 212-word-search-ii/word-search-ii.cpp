class TrieNode{
public:
    TrieNode* links[26];
    bool flag = false;

    bool containKeys(char ch) { return links[ch - 'a'] != nullptr; };
    void put(char ch, TrieNode* node) { links[ch - 'a'] = node; };
    TrieNode* getKey(char ch) { return links[ch - 'a']; };
    void setEnd() { flag = true; };
    bool isEnd() { return flag; };
};

class TrieTree{
private:
    TrieNode* root;
public:
    TrieTree(){ root = new TrieNode(); };
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containKeys(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }
    TrieNode* getRoot() { return root; };
};
class Solution {
public:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n = 0, m = 0;
    void dfsBacktrack(vector<vector<char>>& board, int i, int j, TrieNode* node, 
                      string& currentWord, unordered_set<string>& resultSet) {
        
        char ch = board[i][j];
        if(ch == '#') return;
        if(!node->containKeys(ch)) return; // if trie dosn't contain that word

        node = node->getKey(ch);
        currentWord.push_back(ch);
        if(node->isEnd()) resultSet.insert(currentWord);

        board[i][j] = '#';
        for(auto dir : directions) {
            int nrow = i + dir[0];
            int ncol = j + dir[1];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                dfsBacktrack(board, nrow, ncol, node, currentWord, resultSet);
            }
        }

        // backtrack
        board[i][j] = ch;
        currentWord.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree trie;
        for(string& word : words) {
            trie.insert(word);
        }
        n = board.size();
        m = board[0].size();
        vector<string> res;
        unordered_set<string> resultSet;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string currentWord = "";
                dfsBacktrack(board, i, j, trie.getRoot(), currentWord, resultSet);
            }
        }
        res.assign(resultSet.begin(), resultSet.end());
        return res;
    }
};