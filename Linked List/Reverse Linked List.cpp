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

//Approach - II (recusive)
//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    ListNode* last = NULL;
    ListNode* solve(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }

        ListNode* rVal = solve(head->next);
        
        if(rVal == NULL) {
            last = head;
        } else {
            head->next->next = head;
            head->next = NULL;
        }

        return last;
    }

    ListNode* reverseList(ListNode* head) {
       return  solve(head);
    }
};
