//TC = (n)
class Solution {
  public:
    int solve(Node* node) {
        if(node == NULL) {
            return 0;
        }
        
        int left  = solve(node->left);
        int right = solve(node->right);
        
        int temp = node->data + right + left;
        node->data = left+right;
        
        
        return temp;
    }
  
    void toSumTree(Node *node) {
        solve(node);
    }
};
