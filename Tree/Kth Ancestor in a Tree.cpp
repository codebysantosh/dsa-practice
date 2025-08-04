//T.C =(n)
//S.C = (h)
class Solution {
  public:
    int solve(Node* root, int k, int node, int &ans) {
        if(root == NULL) {
            return -1;
        }
        
        if(root->data == node) {
            return 1;
        }
        
        int left  = solve(root->left, k, node, ans);    
        int right = solve(root->right, k, node, ans);
        
        int dist = max(left, right);
        
        if(dist != -1) {
            if(dist == k) {
                ans = root->data;
            } else {
                return dist+1;
            }
        }
        
        return -1;
    }
  
    int kthAncestor(Node *root, int k, int node) {
        int ans = -1;
        solve(root, k, node, ans);
        return ans;
    }
};
