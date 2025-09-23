class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr != NULL) {
            if(curr->child != NULL) {
                Node* child = curr->child;
                Node* plusOne = curr->next;

                // to connect them in the linear order
                child->prev = curr;
                curr->next = child;
                // to set the child null
                curr->child = NULL;

                // try to find the last node in the child trail
                Node* tail = child; 
                while(tail->next != NULL) {
                    tail = tail->next;
                }

                tail->next = plusOne;
                if(plusOne != NULL) {
                    plusOne->prev = tail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};