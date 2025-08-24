//Approach - I 
//T.C = O(n)
//S.C = O(n)
class Solution {
public:
    vector<int> arr;

    Solution(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL) {
            int val = temp->val;
            arr.push_back(val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int n = arr.size();
        int idx = rand() % n;
        return arr[idx];
    }
};

//Approach - II 
//T.C = O(n)
//S.C = O(1)
