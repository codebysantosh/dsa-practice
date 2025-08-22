//Approach-1 (Recursion)
//T.C : O(m+n) - total number of nodes
//S.C : O(1) (ignoring recursive stack space)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }
        
        ListNode* result = NULL;

        if(list1->val < list2->val) {
            result = list1;
            list1->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

//Approach-2 (Iterative)
//T.C : O(m+n) - total number of nodes
//S.C : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while(head1 && head2) {
            if(head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            } 
            temp = temp->next;
        }

        if(head1 == NULL) {
            temp->next = head2;
        } else {
            temp->next = head1;
        }

        return head->next;
    }
};
