//T.C : O(N*N*M)
//S.C : Auziliary Space = O(1) and O(N*M) – because of the recursion. 
class Solution {
  public:
    Node* mergeTwoSortedList(Node* head1, Node* head2) {
        if(!head1) {
            return head2;
        } 
        
        if(!head2) {
            return head1;
        }
        
        Node* result = NULL;
        if(head1->data < head2->data) {
            result = head1;
            result->bottom = mergeTwoSortedList(head1->bottom, head2);
        } else {
            result = head2;
            result->bottom = mergeTwoSortedList(head1, head2->bottom);
        }
        
        return result;
    }
  
    Node *flatten(Node *root) {
        if(root == NULL) {
            return NULL;
        }
        
        Node* head = flatten(root->next);
        
        return mergeTwoSortedList(root, head);
    }
};
