//Approach-1 (Recur + Memo, starting from i = 0, j = 0)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    int t[501][501];

    int solve(string &word1, string &word2, int i, int j) {
        if(i == m) {
            return n-j; //insert in s1
        } else if(j == n) {
            return m - i; //delete from s1 
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(word1[i] == word2[j]) {
            return t[i][j] = solve(word1, word2, i+1, j+1);
        } else {
            int ins = 1 + solve(word1, word2, i, j+1);
            int del = 1 + solve(word1, word2, i+1, j);
            int rep = 1 + solve(word1, word2, i+1, j+1);

            return t[i][j] = min({ins, del, rep});
        }

        return -1;
    }

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        memset(t, -1, sizeof(t));

        return solve(word1, word2, 0, 0);
    }
};

//Approach-2 (Recur + Memo, starting from m, n)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[501][501];

    int solve(string &word1, string &word2, int m, int n) {
        if(m == 0 || n == 0) {
            return m+n;
        }

        if(t[m][n] != -1) {
            return t[m][n];
        }

        if(word1[m-1] == word2[n-1]) {
            return t[m][n] = solve(word1, word2, m-1, n-1);
        } else {
            int ins = 1 + solve(word1, word2, m, n-1);
            int del = 1 + solve(word1, word2, m-1, n);
            int rep = 1 + solve(word1, word2, m-1, n-1);

            return t[m][n] = min({ins, del, rep});
        }

        return -1;
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        memset(t, -1, sizeof(t));

        return solve(word1, word2, m, n);
    }
};

//Approach-3 (Using Bottom Up derived from Approach-1)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> t(m+1, vector<int> (n+1));

        for(int i = 0; i<=m; i++) {
            for(int j = 0; j<=n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = i+j;
                } else if(word1[i-1] == word2[j-1]) {
                    t[i][j] = t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j], t[i-1][j-1]});
                }
            }
        }

        return t[m][n];
    }
};
