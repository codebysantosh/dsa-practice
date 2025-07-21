//Approach-1 (Recursion + Memoization using LCS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int n;
    int t[1001][1001];

    int LCS(string &s1, string &s2, int i, int j) {
        if(i == n || j == n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s1[i] == s2[j]) {
            return t[i][j] = 1 + LCS(s1, s2, i+1, j+1);
        } else {
            return t[i][j] = max(LCS(s1, s2, i+1, j), LCS(s1, s2, i, j+1));
        }
    }

    int longestPalindromeSubseq(string s1) {
        n = s1.size();
        memset(t, -1, sizeof(t));

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return LCS(s1, s2, 0, 0);
    }
};

//Approach-1 (Bottom up using LCS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int n;

    int LCS(string &s1, string &s2) {
        int n = s1.size();

        vector<vector<int>> t(n+1, vector<int> (n+1));

        for(int i = 0; i<=n; i++) {
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

        return t[n][n];
    }

    int longestPalindromeSubseq(string s1) {
        n = s1.size();

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return LCS(s1, s2);
    }
};

//Approach-2 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[1001][1001];
    
    int LPS(string &s, int i, int j) {
        if(i > j) {
            return 0;
        }

        if(i == j) {
            return 1;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s[i] == s[j]) {
            return t[i][j] = 2 + LPS(s, i+1, j-1);
        } else {
            return t[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        memset(t, -1, sizeof(t));
        return LPS(s, 0, s.size()-1);
    }
};

//Approach-3 (Bottom Up - My Favourite Blue Print of Pallindrome Qns)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> t(n, vector<int> (n));
        //t[i][j] = LPS in s[i...j]

        for(int i = 0; i<n; i++) {
            t[i][i] = 1; //1 length is always a palindromic 
        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i+L-1;

                if(s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }

        return t[0][n-1]; //LPS of whole string s[0..n-1]
    }
};
