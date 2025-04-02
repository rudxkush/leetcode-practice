class MyCircularQueue {
public:
    vector<int> q;
    int head, tail, size;
    MyCircularQueue(int k) {
        q.resize(k);
        head = -1;
        tail = -1; 
        size = k;
    }
    
    bool enQueue(int value) {
        if((tail + 1) % size == head) return false;
        else if(head == -1) { 
            head = 0;
            tail = 0;
            q[tail] = value;
            return true;
        } else {
            tail = (tail + 1) % size; 
            q[tail] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(head == -1) return false;
        else if(head == tail) {
            // int temp = q[head];
            head = -1;
            tail = -1;
            return true;
        } else {
            // int temp = q[head];
            head = (head + 1) % size;
            return true;
        }
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[tail];
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        if((tail + 1) % size == head) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */