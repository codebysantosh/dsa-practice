//Kosaraju's Algorithm :     Time  : O(V+E), V = # vertices, E = # edges , Space : O(V)
class Solution {
  public:
    void dfsFill(vector<vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        
        for(auto &v :adj[u]) {
            
            if(!visited[v]) {
                dfsFill(adj, v, visited, st);
            }
        }
        
        st.push(u);
    }
    
    void dfsTraversal(vector<vector<int>> &adjReversed, int u, vector<bool> &visited) {
        visited[u] = true;
        
        for(auto &v : adjReversed[u]) {
            
            if(!visited[v]) {
                dfsTraversal(adjReversed, v, visited);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        //step - 1 store topo order
        int V = adj.size();
        
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            
            if(!visited[i]) {
                dfsFill(adj, i, visited, st);
            }
        }
        
        //step - 2 make a adjReversed
        
        vector<vector<int>> adjReversed(V);
        
        for(int u = 0; u<V; u++) {
            for(auto &v : adj[u]) {
                adjReversed[v].push_back(u);
            }
        }
        
        //step - 3 do dfs treversal in topo order
        int sccCount = 0;
        
        visited = vector<bool> (V, false);
        
        while(!st.empty()) {
            
            int node = st.top();
            st.pop();
            
            if(!visited[node]) {
                dfsTraversal(adjReversed, node, visited);
                sccCount++;
            }
        }
        
        return sccCount;
    }
};
