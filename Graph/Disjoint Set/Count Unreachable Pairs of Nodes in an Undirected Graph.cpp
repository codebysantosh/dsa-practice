//DSU : Time complexity: O(V+E) ,  Here 'V' is the number of nodes and 'E' is the total number edges.
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

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        unordered_map<int, int> mp;
    
        for(auto &vec : edges) {
            int a = vec[0];
            int b = vec[1];

            unioon(a, b);
        }   

        for(int i = 0; i<n; i++) {
            int papa = find(i);
            mp[papa]++;
        }

        long long result = 0;
        int remaining = n;
        for(auto &comp : mp) {
            long long size = comp.second;
            result += size * (remaining - size);
            remaining = remaining - size;
        }

        return result;
    }
};
