//Approach-1 (Recursion + Memo)
//Recursion T.C : O(m*n)
//Memo T.C      : O(m*n)
class Solution {
public:
    int t[101][101];

    int solve(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid) {
        if(i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        
        if(i == m-1 && j == n-1) {
            return 1;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j+1, m, n, obstacleGrid);
        int down = solve(i+1, j, m, n, obstacleGrid);


        return t[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));
        return solve(0, 0, m, n, obstacleGrid);
    }
};

//Approach-2 (Bottom Up). T.C : O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int> (n, 0));

        //fill 0th row
        for(int col = 0; col<n; col++) {
            if(col > 0 && obstacleGrid[0][col-1] == 1) {
                t[0][col] = 0;
                obstacleGrid[0][col] = 1; //Bcz now it's not possible to reach any cell in first row from this cell onwards
            }else if(obstacleGrid[0][col] == 1) {
                t[0][col] = 0;
            } else {
                t[0][col] = 1;
            }
        }

        //fill 0th col
        for(int row = 0; row<m; row++) {
            if(row > 0 && obstacleGrid[row-1][0] == 1) {
                t[row][0] = 0;
                obstacleGrid[row][0] = 1; //Bcz now it's not possible to reach any cell in first col from this cell onwards
            }else if(obstacleGrid[row][0] == 1) {
                t[row][0] = 0;
            } else {
                t[row][0] = 1;
            }
        }

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }

        return t[m-1][n-1];
    }
};
