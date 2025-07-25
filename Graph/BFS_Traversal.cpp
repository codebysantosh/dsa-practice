//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    void BFS(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        result.push_back(u);
        
        
        while(!q.empty()) {
            
            int u = q.front();
            q.pop();
            
            for(auto v : adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }   
        }
    }
  
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        
        vector<bool> visited(n, false);
        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                BFS(adj, i, visited, result);
            }
        }
        
        return result;
    }
};
