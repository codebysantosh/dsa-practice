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

        if(px == py) return;

        if(rank[px] > rank[py]) {
            parent[py] = px;
        } else if(rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }
        
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }    

        int component = n;

        for(auto &vec : connections) {

            int u = vec[0];
            int v = vec[1];

            if(find(u) != find(v)) {
                unioon(u, v);
                component--;
            }
        }

        return component-1;
    }
};
