//Approach-1 - Recursion + Memoization
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &t) {
        if(i == m-1 && j == n-1) {
            return 1; //we found 1 path to reach [m-1][n-1]
        }

        if(i >= m || i < 0 || j >= n || j < 0) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int rigth = solve(i, j+1, m, n, t);
        int down = solve(i+1, j, m, n, t);

        return t[i][j] = rigth+down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int> (n+1, -1));
        return solve(0, 0, m, n, t);
    }
};

//Approach-2 (using Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int> (n));
        //t[i][j] = total no of ways to reach [i][j] from [0][0]

        t[0][0] = 1; //total ways to reach 0,0 from 0,0

        //fill 0th row
        for(int j = 1;  j<n; j++) {
            t[0][j] = 1;
        }

        //fill 0th col
        for(int i = 1; i<m; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};
