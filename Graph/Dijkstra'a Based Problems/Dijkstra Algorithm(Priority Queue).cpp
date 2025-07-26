//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
class Solution {
  public:
    typedef pair<int, int> p;
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int wt= vec[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> result(V, INT_MAX);
        
        pq.push({0, src});
        result[src] = 0;
        
        while(!pq.empty()) {
            
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto &vec : adj[node]) {
                
                int adjNode = vec.first;
                int dist    = vec.second;
                
                if(d+dist < result[adjNode]) {
                    
                    result[adjNode] = d+dist;
                    pq.push({(d+dist), adjNode});
                }
            }
        }
        
        return result;
    }
};
