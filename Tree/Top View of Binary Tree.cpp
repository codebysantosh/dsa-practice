//Approach - I (BFS)
class Solution {
  public:
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int, int> mp;
        
        while(!q.empty()) {
            
            Node* curr = q.front().first;
            int x = q.front().second;
            q.pop();
            
            if(!mp.count(x)) {
                mp[x] = curr->data;
            }
            
            if(curr->left != NULL) {
                q.push({curr->left, x-1});
            }
            
            if(curr->right != NULL) {
                q.push({curr->right, x+1});
            }
        }
        
        vector<int> result;
        
        for(auto &it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
