//Using BFS : O(m+n)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(auto &v : rooms[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        for(int i = 0; i<n; i++) {
            if(visited[i] == false) {
                return false;
            }
        }

        return true;
    }
};

//using DFS : O(m+n)
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int curr, vector<bool> &visited) {
        visited[curr] = true;

        for(auto &key : rooms[curr]) {
            if(!visited[key]) {
                dfs(rooms, key, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        dfs(rooms, 0, visited);

        for(auto x : visited) {
            if(x == false) return false;
        }

        return true;
    }
};
