/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* iterA = headA;    
        ListNode* iterB = headB;
        while(iterA != iterB){
            if (iterA == NULL) iterA = headB;
            else iterA = iterA->next;

            if (iterB == NULL) iterB = headA;
            else iterB = iterB->next;
        }
        return iterA;

        // ListNode* iterA = headA;
        // ListNode* iterB = headB;
        // int lenA = 0, lenB = 0;
        // while (iterA != NULL) { lenA++; iterA = iterA->next; }
        // while (iterB != NULL) { lenB++; iterB = iterB->next; }
        
        // // Reset iterators
        // iterA = headA;
        // iterB = headB;
        
        // // Adjust starting points to align the lists
        // if (lenA > lenB) {
        //     for (int i = 0; i < lenA - lenB; i++) {
        //         iterA = iterA->next;
        //     }
        // } else {
        //     for (int i = 0; i < lenB - lenA; i++) {
        //         iterB = iterB->next;
        //     }
        // }
        // while(iterA != nullptr && iterB != nullptr) {
        //     if(iterA == iterB) {
        //         return iterA;
        //     }
        //     iterA = iterA->next;
        //     iterB = iterB->next; 
        // }
        // return nullptr;
    }
};