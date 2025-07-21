//Approach-1 (Recur + Memo - Using Straight Forward Pallindromic Property)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int t[501][501];

    int solve(string &s, int i, int j) {
        if(i >= j) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s[i] == s[j]) {
            return t[i][j] = solve(s, i+1, j-1);
        }
        
        return t[i][j] = 1 + min(solve(s, i, j-1), solve(s, i+1, j));
    }

    int minInsertions(string s) {
        int n = s.size();

        memset(t, -1, sizeof(t));

        return solve(s, 0, n-1);
    }
};

//Approach-2 (Bottom Up - Using my favourite Palindrome Blue Print)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> t(n, vector<int> (n));
        //State : dp[i][j] = min insertion to make s[i..j] a palindrome

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L-1;

                if(s[i] == s[j]) {
                    t[i][j] = t[i+1][j-1];
                } else {
                    t[i][j] = 1 + min(t[i][j-1], t[i+1][j]);
                }

            }
        }

        return t[0][n-1];
    }
};

//Approach-3 (Using LCS)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int t[501][501];

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

    int minInsertions(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));

        string temp = s;
        reverse(begin(temp), end(temp));

        int lcs_length = LCS(s, temp, n, n);

        return n - lcs_length;
    }
};
