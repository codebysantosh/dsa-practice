//Approach - Using Multi-Source BFS
//T.C : O(m * n) , We will visit all cells once
//S.C : O(m * n), in worst case queue will contain all the cells
class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j}); //Storing all possible sources at once in the queue
                } else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        auto issafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        int time = 0;
        while(!q.empty()) {
            int N = q.size();
            //because we want to cover all neighbours of a node
            //at once which are affected in a particular time frame
            while(N--) {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                for(auto &dir : directions) {
                    int x = i+dir[0];
                    int y = j+dir[1];

                    if(issafe(x, y) && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        freshCount--;
                    }
                }
            }

            if(!q.empty()) time++;
        }

        return freshCount == 0 ? time : -1;
    }
};
