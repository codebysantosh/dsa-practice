//Approach-1 (Recursion + Memoization) - (TLE)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    int t[2001][2001];
    bool isPalindrome(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int i, int j) {
        if(i >= j) {
            return 0;
        }

        if(isPalindrome(s, i, j)) {
            return t[i][j] = 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int cut = INT_MAX;
        for(int k = i; k<=j-1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            cut = min(cut, temp);
        }

        return t[i][j] = cut;
    }

    int minCut(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1);
    }
};

//Approach-2 (Bottom-Up) : Accepted
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> t(n, vector<bool> (n, false));
        //t[i][j] = True ; //means str(i,j) is a pallindrome else not
        //Length = 1 are always pallindrome

        for(int i = 0; i<n; i++) {
            t[i][i] = true;
        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i+L-1;

                if(L == 2) {
                    t[i][j] = (s[i] == s[j]);
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                }
            }
        }

        vector<int> dp(n);
        //dp[i] = min cut required to cut a string s[0..i] into palindromes

        for(int i = 0; i<n; i++) {
            if(t[0][i] == true) { //s[0..i] is a palindrome
                dp[i] = 0; //no cut required
            } else {
                dp[i] = INT_MAX;
                for(int k = 0; k<i; k++) {
                    if(t[k+1][i] == true && 1 + dp[k] < dp[i]) {
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }

        return dp[n-1]; //entire string min cut required to split it into palindromes only
    }
};
