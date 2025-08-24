//T.C : O(m+n)
//T.C : O(1) (Ignoring recursion stack space)
class Solution {
  public:
    struct Node* merge(Node *node1, Node *node2) {
        if(node1 == NULL) {
            return node2;
        }
        
        if(node2 == NULL) {
            return node1;
        }
        
        Node* result = NULL;
        
        if(node1->data < node2->data) {
            result = node1;
            result->next = merge(node1->next, node2);
        } else {
            result = node2;
            result->next = merge(node1, node2->next);
        }
        
        return result;
    }
  
  
    struct Node* reverse(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node* last = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return last;
    }

    struct Node *mergeResult(Node *node1, Node *node2) {
        struct Node* merged = merge(node1, node2);
        
        return reverse(merged);
    }
};
