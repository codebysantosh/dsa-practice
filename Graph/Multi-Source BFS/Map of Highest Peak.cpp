//Approach - Using Multi-Source BFS
//T.C : O(m * n) , We will visit all cells once
//S.C : O(m * n), in worst case queue will contain all the cells
class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> result(m, vector<int> (n, -1));
      
        queue<pair<int, int>> q;
        //Height of water cells must be 0 only
        //T.C : O(m*n)
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(isWater[i][j] == 1) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x<m && y >= 0 && y<n;
        };

        while(!q.empty()) {

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(auto &dir : directions) {
                int x = i+dir[0];
                int y = j+dir[1];

                if(isSafe(x, y) && isWater[x][y] == 0) {
                    result[x][y] = result[i][j] + 1;
                    isWater[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return result;
    }
};
