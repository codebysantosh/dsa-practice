//Approach-1 (Time : O(n), Space : O(1))
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenSt = head->next;

        while(even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = even->next;

            even->next = odd->next;
            even = odd->next;
        }

        odd->next = evenSt;

        return head;
    }
};
