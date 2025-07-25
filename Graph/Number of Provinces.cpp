//Approach-1 : [ Using DFS - Creating our own Map as graph ]
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;

         //Visit neighbours
        for(auto v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<bool> visited(n, false);
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};

//Approach-2 : [ Using DFS - Using given input graph]
class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool> &visited) {
        visited[u] = true;

        //Visit neighbours
        for(int v = 0; v<n; v++) {
            if(!visited[v] && isConnected[u][v] == 1) {
                dfs(isConnected, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        int count = 0;

        vector<bool> visited(n, false);
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }  

        return count; 
    }
};

//Approach-3 : [ Using BFS : Creating our own Map as graph ]
class Solution {
public:
    void bfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(auto v : adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};

//Approach-4 : [ Using BFS - Using given input graph]
class Solution {
public:
    int n;

    void bfs(vector<vector<int>>& isConnected, int u, vector<bool> &visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int v = 0; v<n; v++) {
                if(!visited[v] && isConnected[u][v] == 1) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        int count = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }
};
