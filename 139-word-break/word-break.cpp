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
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieTree trie;
        for(auto word : wordDict) trie.insert(word);
        int n = s.length();
        vector<bool> validPart(n + 1, false); 
        validPart[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            TrieNode* node = trie.getRoot();
            for(int j = i; j < n; j++) {
                if(!node->containKeys(s[j])) {
                    break;
                }
                node = node->getKey(s[j]);
                if(node->isEnd() && validPart[j + 1]) {
                    validPart[i] = true;
                    break;
                }
            }
        }
        return validPart[0];
    }
};