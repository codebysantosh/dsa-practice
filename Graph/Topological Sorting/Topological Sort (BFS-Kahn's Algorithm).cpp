//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(V, 0);
        
        //1
        for(auto vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        vector<int> result;
        
        //2. Fill que, indegree with 0
        for(int i = 0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                result.push_back(i);
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
                    result.push_back(v);
                }
            }
        }
        
        return result;
    }
};
