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
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* curr = start;
        ListNode* prev = NULL;
        ListNode* stop = end->next;
        while(curr != stop) {
            ListNode* nextNodes = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNodes;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        for(int i = 1; i < left; i++) {
            // Avoids NULL references on the right of the LL
            if(curr->next == NULL && i < left) return dummy->next;
            curr = curr->next;
        }
        int winSize = right - left;
        ListNode* end = curr->next;
        for(int i = 0; i < winSize; i++) {
            // Avoids NULL references on the left of the LL
            if(end->next == NULL && i < right) {
                break;
            }
            end = end->next;
        }

        ListNode* revHead = curr->next;
        ListNode* prev = curr;
        ListNode* nextNodes = end->next;
        ListNode* revLL = reverse(revHead, end);
        prev->next = revLL;
        revHead->next = nextNodes;
        
        return dummy->next;
    }
};