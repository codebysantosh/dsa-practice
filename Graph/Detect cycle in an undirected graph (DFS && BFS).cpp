//Using DFS Traversal
//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    bool DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, int parent) {
        visited[u] = true;
        
        for(auto v : adj[u]) {
            if(v == parent) {
                continue;
            }
            
            if(visited[v] == true) {
                return true;
            }
            
            if(DFS(adj, v, visited, u)){
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && DFS(adj, i, visited, -1)) {
                return true;
            }
        }
        
        return false;
    }
};

//Using BFS Traversal
//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    bool BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;
        
        while(!q.empty()) {
            
            int u = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto v : adj[u]) {
                if(!visited[v]) {
                    q.push({v, u});
                    visited[v] = true;
                } else if(v != p) {
                    return true;
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && BFS(adj, i, visited)) {
                return true;
            }
        }
        
        return false;
    }
};
