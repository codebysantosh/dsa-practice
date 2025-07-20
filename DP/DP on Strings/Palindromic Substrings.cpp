//Approach-1 (Simply check all substrings possilbe)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:

    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(s[i] == s[j]) {
            return check(s, i+1, j-1);
        }

        return false;

    }

    int countSubstrings(string s) {
        int n = s.length();

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { //check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};


//Approach-2 (Memoize the approach above)
//T.C : O(n^2) - Every subproblem is being computed only once and after that it's being reused
//S.C : O(n^2)
class Solution {
public:
    int t[1001][1001];

    bool check(string &s, int i, int j) {
        if(i>j) {
            return true;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }

        return false;
    }

    int countSubstrings(string s) {
        int n = s.size();

        memset(t, -1, sizeof(t));

        int count = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {

                if(check(s, i, j)) {
                    count++;
                }
                
            }
        }

        return count;
    }
};

//Approach-3(Bottom Up - My Favourite Blue Print of Pallindrome Qns)
//T.C : O(n^2)
//S.C ; O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool> (n, false));
        //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices
      
        int count = 0;

        for(int l = 1; l<=n; l++) {

            for(int i = 0; i+l-1<n; i++) {
                int j = i+l-1;

                if(i == j) { //Single characters are palindrome
                    t[i][j] = true;
                } else if(i+1 == j) { //Strings of 2 Length
                    t[i][j] = (s[i] == s[j]);
                } else {
                    t[i][j] = ((s[i] == s[j]) && (t[i+1][j-1]));
                }

                if(t[i][j] == true) {
                    count++;
                }
            }
        }

        return count;
    }
};
