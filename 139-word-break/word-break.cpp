class Node {
public:
    // Every index corresponding to the lower case letter
    // has a reference ptr to another node
    Node* links[26];
    bool flag = false;
    bool containKeys(char ch) { return (links[ch - 'a'] != NULL); }
    // putting ptr to node char list to another newly created node
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKeys(word[i])) {
                node->put(word[i], new Node());
            }
            // move to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKeys(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    Node* getRoot() { return root; }
    bool checkWordFromIndex(const string& s, int start, vector<int>& dp) {
        Node* node = root;
        for (int i = start; i < s.size(); ++i) {
            if (!node->containKeys(s[i]))
                return false;
            node = node->get(s[i]);
            if (node->isEnd() && dp[i + 1])
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string& word : wordDict) {
            trie.insert(word);
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1; 

        for (int i = n - 1; i >= 0; i--) {
            Node* node = trie.getRoot(); 
            for (int j = i; j < n; ++j) {
                if (!node->containKeys(s[j]))
                    break;
                node = node->get(s[j]);
                if (node->isEnd() && dp[j + 1]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};