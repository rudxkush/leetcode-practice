class Node {
public:
    // Every index corresponding to the lower case letter
    // has a reference ptr to another node
    Node* links[26];
    bool flag = false;
    // whether the node already contains the letter or not
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

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
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containKeys(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};