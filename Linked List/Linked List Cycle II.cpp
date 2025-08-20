//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                break;
            }
        }

        if(slow != fast) {
            return NULL;
        }

        ListNode* p = head;

        while(p != slow) {
            p = p->next;
            slow = slow->next;
        }

        return p;
    }
};
