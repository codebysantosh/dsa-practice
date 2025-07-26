class Solution {
  public:
    typedef pair<int, int> p;
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<p>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1);

        for(int i = 1; i<=n; i++) {
            parent[i] = i;
        }
        
        pq.push({0, 1});
        result[1] = 0;
        
        while(!pq.empty()) {
            
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto &vec : adj[node]) {
                
                int adjNode = vec.first;
                int dist = vec.second;
                
                if(d + dist < result[adjNode]) {
                    result[adjNode] = d+dist;
                    pq.push({d+dist, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        
        vector<int> path;
        int node = n;
        
        if(result[n] == INT_MAX) {
            return {-1};
        }
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node);
        
        reverse(path.begin(), path.end());
        
        path.insert(path.begin(), result[n]);
        
        return path;
    }
};
