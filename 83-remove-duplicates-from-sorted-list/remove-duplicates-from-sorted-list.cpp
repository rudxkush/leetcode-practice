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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(head != NULL) {
            if(current->next == NULL || current->val != head->val) {
                current->next = head;
                current = current->next;
            } 
            head = head->next;
        }

        current->next = NULL;
        return dummy->next;
    }
};