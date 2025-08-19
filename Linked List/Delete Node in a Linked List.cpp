//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        
        while(node != NULL && node->next != NULL) {
            node->val = node->next->val;

            prev = node;

            node = node->next;
        }

        prev->next = NULL;
        delete(node);
    }
};
