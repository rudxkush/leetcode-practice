class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* iter = head;
        while(iter != NULL) {
            len++;
            iter = iter->next;
        }

        if(k > len) return head;

        iter = head;
        for(int i = 1; i < k; i++) {
            iter = iter->next;
        }
        ListNode* first = iter;

        iter = head;
        for(int i = 1; i < len - k + 1; i++) {
            iter = iter->next;
        }
        ListNode* second = iter;

        swap(first->val, second->val);

        return head;
    }
};