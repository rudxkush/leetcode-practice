/**************************LEAST RECENTLY USED CACHE**************************
1. Initialize the LRU cache with positve capacity

2. Implement a hash map to store key-value pairs, enabling O(1) retrieval.

3. Implement DLL in such a way that the most recently used is at the first
and least at last so that the deletion of least recently used becomes easy.
******************************************************************************/
class LRUCache {
private:
    class ListNode {
    public:
        int key;
        int value;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> hashMap;

    // Remove a node from the doubly linked list
    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add a node to the front of the list
    void addToFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            ListNode* node = hashMap[key];
            
            // Remove the node from its current position
            removeNode(node);
            
            // Move the node to the front (most recently used)
            addToFront(node);
            
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // If key already exists, update its value and move to front
        if (hashMap.find(key) != hashMap.end()) {
            ListNode* existingNode = hashMap[key];
            existingNode->value = value;
            
            // Remove from current position and move to front
            removeNode(existingNode);
            addToFront(existingNode);
            return;
        }
        
        if (hashMap.size() >= capacity) {
            // Remove from the end of the list (least recently used)
            ListNode* lru = tail->prev;
            removeNode(lru);
            hashMap.erase(lru->key);
            delete lru;
        }
        
        // Create and add new node
        ListNode* newNode = new ListNode(key, value);
        hashMap[key] = newNode;
        addToFront(newNode);
    }

    ~LRUCache() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
};