class Solution {
  public:
    void DFS(vector<int> adj[], int u, vector<bool> &visited) {
        visited[u] = true;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if(!visited[*it]) {
                DFS(adj, *it, visited);
            }
        }
    }
  
    bool isConnected(int V, vector<int> adj[]) {
        
        int nonZeroDegree = -1;
        
        for(int i = 0; i<V; i++) {
            if(adj[i].size() > 0) {
                nonZeroDegree = i;
                break;
            }
        }
        
        
        vector<bool> visited(V, false);
        
        // Start DFS traversal from a vertex with non-zero degree
        DFS(adj, nonZeroDegree, visited);
        
        // Check if all non-zero degree vertices are visited
        for(int i = 0; i<V; i++) {
            if(adj[i].size() > 0 && visited[i] == false) {
                return false;
            }
        }
        
        return true;
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
        
        //check if all non-zero degree waale vertices are connected
        if(isConnected(V, adj) == false) {
            return 0;
        } 
        
        int oddDegree = 0;
        
        //Count odd degree wala vertices
        for(int i = 0; i<V; i++) {
            if(adj[i].size() % 2 != 0) {
                oddDegree++;
            }
        }
        
        
        if(oddDegree > 2) 
            return 0; //None
            
        if(oddDegree == 2)
            return 1; //EP
            
        return 2;    //EC
    }
};
