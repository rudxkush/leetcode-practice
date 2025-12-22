class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* stop = end->next;

        while (curr != stop) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int groupSize = 1;
        while (curr->next) {
            ListNode* kth = curr;
            int cnt = 0;
            while (cnt < groupSize && kth->next) {
                kth = kth->next;
                cnt++;
            }
            if (cnt % 2 == 0) {
                ListNode* head = curr->next;
                ListNode* nextNodes = kth->next;

                ListNode* revLLHead = reverse(head, kth);

                curr->next = revLLHead;
                head->next = nextNodes;
                curr = head; 
            } else {
                for (int i = 0; i < cnt; i++) {
                    curr = curr->next;
                }
            }
            groupSize++;
        }
        return dummy->next;
    }
};
