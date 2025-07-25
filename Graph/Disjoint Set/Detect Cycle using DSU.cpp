//TC = O(V+E)
//SC = O(V)
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        
        return parent[i] = find(parent[i]);
    }
    
    void unioon(int x, int y) {
        
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) {
            return;
        }
        
        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    
    int detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);
        
        for(int i = 0; i<V; i++) {
            parent[i] = i;
        }
        
        for(int u = 0; u<V; u++) {
            for(auto &v : adj[u]) {
                
                if(u < v) {
                    if(find(u) == find(v)) {
                        return true;
                    } else {
                        unioon(u, v);
                    }
                }
            }
        }
        
        return false;
    }
};
