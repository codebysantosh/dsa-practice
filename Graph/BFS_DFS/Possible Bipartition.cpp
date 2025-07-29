//Using BFS - O(V+E)
class Solution {
public:
    bool bfs(unordered_map<int, vector<int>> &adj, int curr, vector<int> &color, int currColor) {
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(auto &v : adj[u]) {
                if(color[v] == -1) {
                    q.push(v);
                    color[v] = 1 - color[u];
                } else if(color[v] == color[u]) {
                    return false;
                }
            } 
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec : dislikes) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1);

        for(int i = 0; i<n; i++) {
            if(color[i] == -1) {
                if(bfs(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;;
    }
};


//using DFS : O(V+E)
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &adj, int curr, vector<int> &color, int currColor) {
        color[curr] = currColor;

        for(auto &v : adj[curr]) {
            if(color[v] == color[curr]) {
                return false;
            }

            if(color[v] == -1) {
                int colorV = 1-color[curr];
                if(dfs(adj, v, color, colorV) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec : dislikes) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1);

        for(int i = 0; i<n; i++) {
            if(color[i] == -1) {
                if(dfs(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;;
    }
};
