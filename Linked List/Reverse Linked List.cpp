//Approach - I (itrative)
//T.C = O(n)
//S>C = O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while(head != NULL) {
            ListNode* next = head->next;

            head->next = prev;

            prev = head;
            head = next;
        }

        return prev;
    }
};
