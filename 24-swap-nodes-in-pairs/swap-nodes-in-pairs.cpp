/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;
        ListNode *first = head, *temp = 0, *prev = 0;
        head = head->next ? head->next : head;
        ListNode* second = 0;
        while (first && first->next) {
            second = first->next;
            first->next = second->next;
            second->next = first;
            if (prev)
                prev->next = second;
            prev = first;
            first = first->next;
        }
        return head;
    }
};