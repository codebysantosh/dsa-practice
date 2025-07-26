//Approach-1 (Using BFS - Works because all edges are of weight = 1)
class Solution {
public:
    typedef pair<int, int> p;
    vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {-1,0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        queue<p> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int step = 1;

        while(!q.empty()) {

            int N = q.size();

            while(N--) {

                auto &curr = q.front();
                int i = curr.first;
                int j = curr.second;

                q.pop();

                if(i == m-1 && j == n-1) {
                    return step;
                }

                for(auto &dir : directions) {

                    int x = i+dir[0];
                    int y = j+dir[1];

                    if(isSafe(x, y) && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }

            step++;
        }

        return -1;
    }
};

//Approach-2 (Using Dijkstra's Algorithm) - Using Priority_queue (min-heap)
class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while(!pq.empty()) {

            int d = pq.top().first;

            auto &curr = pq.top().second;
            int i = curr.first;
            int j = curr.second;

            pq.pop();

            for(auto &dir : directions) {

                int x = i+dir[0];
                int y = j+dir[1];

                int dist = 1;
                if(isSafe(x, y) && grid[x][y] == 0 && d+dist < result[x][y]) {
                    pq.push({d+dist, {x,y}});
                    result[x][y] = d+dist;
                }
            }    
        }

        if(result[m-1][n-1] != INT_MAX) {
            return result[m-1][n-1]+1;
        }

        return -1;
    }
};

//Approach-3 (Using Dijkstra's Algorithm) - Using queue (min-heap)
//This works because every weight is 1 and it will be similar to min-heap only
class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {-1,0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        queue<p> q;
        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        q.push({0, {0,0}});
        result[0][0] = 0;

        while(!q.empty()) {

            int d = q.front().first;
            pair<int, int> node = q.front().second;
            int i = node.first;
            int j = node.second;

            q.pop();

            for(auto &dir : directions) {

                int x = i+dir[0];
                int y = j+dir[1];

                int dist = 1;

                if(isSafe(x, y) && grid[x][y] == 0 && d+dist < result[x][y]) {
                    q.push({d+dist, {x, y}});
                    result[x][y] = d+dist;
                    grid[x][y] = 1;
                }
            }
        }

        if(result[m-1][n-1] != INT_MAX) {
            return result[m-1][n-1] + 1;
        }

        return -1;
    }
};
