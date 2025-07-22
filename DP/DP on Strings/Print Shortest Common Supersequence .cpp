//Approach-I(BottoM Up)
//T.C = (m*n)
//S.C = (m*n)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> t(m+1, vector<int> (n+1));

        for(int i = 0; i<=m; i++) {
            for(int j = 0; j<=n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = i+j;
                } else if(str1[i-1] == str2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
                }
            }
        }

        string result = "";
        int i = m, j = n;

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                result.push_back(str1[i-1]);
                i--;
                j--;
            } else {
                if(t[i-1][j] < t[i][j-1]) {
                    result.push_back(str1[i-1]);
                    i--;
                } else {
                    result.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while( i > 0) {
            result.push_back(str1[i-1]);
            i--;
        }

        while(j > 0) {
            result.push_back(str2[j-1]);
            j--;
        }

        reverse(begin(result), end(result));
        return result;
    }
};
