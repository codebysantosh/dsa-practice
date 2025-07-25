//Using DFS Traversal
//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    bool DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecu) {
        visited[u] = true;
        inRecu[u]  = true;
        
        for(auto v : adj[u]) {
            if(!visited[v] && DFS(adj, v, visited, inRecu)) {
                return true;
            } else if(inRecu[v] == true) {
                return true;
            }
        }
        
        inRecu[u] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> inRecu(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && DFS(adj, i, visited, inRecu)) {
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
    bool BFS(unordered_map<int, vector<int>> &adj, int V, vector<int> &indegree) {
        queue<int> q;
        
        int count = 0;
        
        //2. Fill que, indegree with 0
        for(int i = 0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        
        //3. Simple BFS
        while(!q.empty()) {
            
            int u = q.front();
            q.pop();
            
            for(auto v : adj[u]) {
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        
        return count == V ? false : true;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        vector<int> indegree(V, 0);
        
        //1
        for(auto vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        return BFS(adj, V, indegree);
    }
};
