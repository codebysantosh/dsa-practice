//Approach - I (BFS)
class Solution {
  public:
    int sumBT(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        queue<Node*> q;
        q.push(root);
        int sum = root->data;
        
        while(!q.empty()) {
            
            Node* curr = q.front();
            q.pop();
            
            if(curr->left != NULL) {
                q.push(curr->left);
                sum += curr->left->data;
            }
            
            if(curr->right != NULL) {
                q.push(curr->right);
                sum += curr->right->data;
            }
        }
        
        return sum;
    }
};

//Approach - II (DFS)
class Solution {
  public:
    int dfs(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int right = root->data + dfs(root->right);
        int left  = root->data + dfs(root->left);
        
        return right+left-root->data;
    }
  
    int sumBT(Node* root) {
        return dfs(root);
    }
};
