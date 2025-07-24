//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool> &visited, vector<int> &result) {
        visited[u] = true;
        result.push_back(u);
        
        for(auto v : adj[u]) {
            if(!visited[v]) {
                DFS(adj, v, visited, result);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<bool> visited(n);
        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                DFS(adj, 0, visited, result);    
            }
        }
        
        return result;
    }
};
