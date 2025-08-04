//Approach - I (using backtracking to count dist)
class Solution {
  public:
    Node* LCA(Node* root, int a, int b) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root->data == a || root->data == b) {
            return root;
        }
        
        Node* left  = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        
        if(left != NULL && right != NULL) {
            return root;
        }
        
        return left == NULL ? right : left;
    }
    
    bool dist(Node* root, int x, int& count) {
        if(root == NULL) {
            return false;
        }
        
        count++;
        if(root->data == x) {
            return true;
        }
        
        if(dist(root->left, x, count) || dist(root->right, x, count)) {
            return true;
        }
        
        count--;
        return false;
    }
  
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        
        int c1 = 0;
        int c2 = 0;
        
        dist(lca, a, c1);
        dist(lca, b, c2);
        
        return (c1 + c2)-2;
    }
};

//Approach - II (Return Aggregation Style (no external variables))
class Solution {
  public:
    Node* LCA(Node* root, int a, int b) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root->data == a || root->data == b) {
            return root;
        }
        
        Node* left  = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        
        if(left != NULL && right != NULL) {
            return root;
        }
        
        return left == NULL ? right : left;
    }
    
    int dist(Node* root, int x) {
        if(root == NULL) {
            return -1;
        }
        
        if(root->data == x) {
            return 0;
        }
        
        int left  = dist(root->left, x);
        if(left != -1) return left+1;
        
        int right = dist(root->right, x);
        if(right != -1) return right+1;
        
        return -1;
    }
  
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        
        int d1 = dist(lca, a);
        int d2 = dist(lca, b);
        
        return d1 + d2;
    }
};
