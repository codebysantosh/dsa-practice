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
        
        int px = find(x);
        int py = find(y);
        
        if(px == py) {
            return;
        }
        
        if(rank[px] > rank[py]) {
            parent[py] = px;
        } else if(rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }
  
    int kruskal(vector<vector<int>> &edges) {
        int sum = 0;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
                
            if(find(u) != find(v)) {
                unioon(u, v);
                sum += w;
            }
        }

        //if(edgesConnexted != V-1) 
	      //"It's not a MST" - REMEMBER THIS ALWAYS if anyone asks you how to check if we formed an MST or not
        
        return sum;
    }
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        parent.resize(V);
        rank.resize(V, 0);
        
        for(int i = 0; i<V; i++) {
            parent[i] = i;
        }
        
        auto comparator = [&](vector<int> &vec1, vector<int> &vec2) {
            return vec1[2] < vec2[2];
        };
        
        sort(begin(edges), end(edges), comparator);
        
        return kruskal(edges);
    }
};
