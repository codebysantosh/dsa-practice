//Using LCS code
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

        string result = "";

        int i = m, j = n;
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                result.push_back(s1[i-1]);
                i--;
                j--;
            } else {
                if(t[i-1][j] > t[i][j-1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        reverse(begin(result), end(result));
        cout<<result<<endl;

        return t[m][n];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1, text2);
    }
};
