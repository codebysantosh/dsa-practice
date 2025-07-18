//Approach-1 (Using Simple LIS recursion+memo) - We sort it in the beginning to get words ordered in ascending order based on length
//T.C : O(n*n*n)
class Solution {
public:
    int n;
    int t[1001][1001];

    bool isPred(string &prev, string &curr) {
        int M = prev.length();
        int N = curr.length();

        if(M >= N || N-M != 1) {
            return false;
        }

        int i = 0, j = 0;

        while(i < M && j < N) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }

        return i == M;
    }

    int solve(vector<string>& words, int idx, int prev) {
        if(idx == n) {
            return 0;
        }

        if(prev != -1 &&t[idx][prev] != -1) {
            return t[idx][prev];
        }

        int take = 0;
        if(prev == -1 || isPred(words[prev], words[idx])) {
            take = 1 + solve(words, idx+1, idx);
        }

        int not_taken = solve(words, idx+1, prev);

        if(prev != -1) {
            t[idx][prev] = max(take, not_taken);
        }

        return max(take, not_taken);
    }

    static bool myFunction(string& s1, string& s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myFunction);
        memset(t, -1, sizeof(t));
        return solve(words, 0, -1);
    }
};

//Approach-2 (Using Simple LIS Bottom Up) - We sort it in the beginning to get words ordered in ascending order based on length
//T.C : O(n*n*n)
class Solution {
public:
    bool isPred(string &prev, string &curr) {
        int M = prev.size();
        int N = curr.size();

        if(M >= N || N-M != 1) {
            return false;
        }

        int i = 0, j = 0;

        while(i < M && j < N) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }

        return i == M;
    }

    static auto myFunction(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), myFunction);
        vector<int> t(n, 1);

        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(isPred(words[j], words[i])) {
                    t[i] = max(t[j] + 1, t[i]);
                    maxL = max(maxL, t[i]);
                }
            }
        }

        return maxL;
    }
};
