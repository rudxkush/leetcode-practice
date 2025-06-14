class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if (k == 0) return head;  
        ListNode* temp = head;
        for(int i = 1; i < (len - k); i++) {
            temp = temp->next;
        }
        ListNode* next = temp->next;
        temp->next = NULL;
        tail->next = head;
        head = next;
        return head;
    }
};