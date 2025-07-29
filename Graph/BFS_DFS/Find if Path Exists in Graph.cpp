//Using DFS : O(m+n)
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
        visited[u] = true;

        for(auto &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        dfs(adj, source, visited);

        return visited[destination];
    }
};


//Using BFS : O(m+n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) {
            return true;
        }

        unordered_map<int, vector<int>> adj;

        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            if(u == destination) {
                return true;
            }

            for(auto &v : adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return false;
    }
};

//using DSU
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

    void unionSet(int x, int y) {

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
            parent[px] =py;
            rank[py]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) {
            return true;
        }
        
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            if(find(u) != find(v)) {
                unionSet(u, v);
            }
        }

        return find(source) == find(destination);
    }
};
