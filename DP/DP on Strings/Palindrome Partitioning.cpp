//Approach-1 (Using DP + Backtracking)
//T.C : O(2^n)
//S.C : O(n^2)
class Solution {
public:

    void solve(string &s, int i, vector<string>& currPartition, vector<vector<bool>>& t, vector<vector<string>>& result) {
        if(i == s.length()) { //I was able to successfully partition the entire string
            result.push_back(currPartition);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            if(t[i][j] == true) { //palindrome
                currPartition.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPartition, t, result);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // Initialize the DP table for palindromic substrings
        //t[i][j] = true -> s[i...j] is a palindrome
        
        for (int i = 0; i < n; ++i) {
            t[i][i] = true; //substring of single character is always a palindrome
        }
        
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s, 0, currPartition, t, result);

        return result;
    }
};
