//T.C : O(m*n)
//S.C : O(m*n)
//Approach-1 (Recursion + Memoization)(-->)
class Solution {
public:
    int m, n;
    int t[1001][1001];

    int solve(string &text1, string& text2, int i, int j) {
        if(i == m || j == n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(text1[i] == text2[j]) {
            return t[i][j] = 1 + solve(text1, text2, i+1, j+1);
        }
         
        return t[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
    }
};

//T.C : O(m*n)
//S.C : O(m*n)
//Approach-1 (Recursion + Memoization)(<--)
class Solution {
public:
    int t[1001][1001];

    int LCS(string &s1, string &s2, int m, int n) {
        if(m == 0 || n == 0) {
            return 0;
        }

        if(t[m][n] != -1) {
            return t[m][n];
        }

        if(s1[m-1] == s2[n-1]) {
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        } else {
            return t[m][n] = max(LCS(s1, s2, m-1, n), LCS(s1, s2, m, n-1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        memset(t, -1, sizeof(t));
        return LCS(text1, text2, m, n);
    }
};

//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int LCS(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m+1, vector<int> (n+1));

        for(int i = 0; i<=m; i++) {
            for(int j = 0; j<=n; j++) {

                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                } else if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[m][n];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1, text2);
    }
};
