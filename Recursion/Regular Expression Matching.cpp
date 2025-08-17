//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, string s, string p) {
        if(j == p.size()) {
            return i == s.size();
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        bool first_char_match = false;

        if(i < s.size() && (p[j] == s[i] || p[j] == '.')) {
            first_char_match = true;
        }

        if(p[j+1] == '*') {
            bool not_take = solve(i, j+2, s, p);
            bool take = first_char_match && solve(i+1, j, s, p);

            return t[i][j] = not_take || take;
        }

        return t[i][j] = first_char_match && solve(i+1, j+1, s, p);
    }

    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};
