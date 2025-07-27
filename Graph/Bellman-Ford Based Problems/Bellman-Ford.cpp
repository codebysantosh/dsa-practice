//TC = O(V*E)
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> result(V, 1e8);
        result[src] = 0;
        
        for(int count = 1; count<=V-1; count++) {
            
            for(auto &edge : edges) {
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
            }
        }
        
        //-ve cycle detection
        for(int count = 1; count <=V-1; count++) {
            
            for(auto &edge : edges) {
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    return {-1};
                }
            }
        }
        
        return result;
    }
};
