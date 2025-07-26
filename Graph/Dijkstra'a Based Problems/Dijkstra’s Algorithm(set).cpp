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
        
        set<p> s;
        vector<int> result(V, INT_MAX);
        
        s.insert({0, src});
        result[src] = 0;
        
        while(!s.empty()) {
            
            auto &it = *s.begin();
            
            int d = it.first;
            int node = it.second;
            
            s.erase(it);
            
            for(auto &vec : adj[node]) {
                
                int adjNode = vec.first;
                int dist    = vec.second;
                
                if(d+dist < result[adjNode]) {
                    
                    if(result[adjNode] != INT_MAX) {
                         auto iter = s.find({result[adjNode], adjNode});
                            pq.erase(iter);
			                  //OR, s.erase({result[adjNode], adjNode});
                    }
                    
                    result[adjNode] = d+dist;
                    s.insert({(d+dist), adjNode});
                }
            }
        }
        
        return result;
    }
};
