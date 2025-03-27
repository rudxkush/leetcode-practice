class LFUCache {
private:
    int capacity, minFreq;
    
    struct Node {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    unordered_map<int, Node*> keyToNode;  // Key to node mapping
    unordered_map<int, list<Node*>> freqList;  // Frequency to list of nodes
    unordered_map<int, list<Node*>::iterator> nodeIter;  // Key to its position in freqList

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq].erase(nodeIter[node->key]);  

        // If the list becomes empty, remove it and update minFreq
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Increase frequency and move node to the next list
        node->freq++;
        freqList[node->freq].push_back(node);
        nodeIter[node->key] = --freqList[node->freq].end();  
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToNode.count(key) == 0) return -1;
        
        Node* node = keyToNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToNode.count(key)) {
            Node* node = keyToNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyToNode.size() >= capacity) {
            // Remove LFU node
            Node* toRemove = freqList[minFreq].front();
            keyToNode.erase(toRemove->key);
            nodeIter.erase(toRemove->key);  
            freqList[minFreq].pop_front();
            delete toRemove;
        }

        // Insert new node
        Node* newNode = new Node(key, value);
        keyToNode[key] = newNode;
        minFreq = 1;
        freqList[1].push_back(newNode);
        nodeIter[key] = --freqList[1].end();  
    }

    ~LFUCache() {
        for (auto& pair : keyToNode) {
            delete pair.second;
        }
    }
};