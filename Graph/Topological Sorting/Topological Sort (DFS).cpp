//TC = O(V+E)
//Sc = O(V)
class Solution {
  public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, stack<int> &st) {
        visited[u] = true;

        //pehle mere ('u' ke node ke ) bachho ko daalo
        for(auto v : adj[u]) {
            if(!visited[v]) {
                DFS(adj, v, visited, st);
            }
        }

        //ab mujhe daalo stack me
        st.push(u);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                DFS(adj, i, visited, st);
            }
        }
        
        
        vector<int> result;
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};
