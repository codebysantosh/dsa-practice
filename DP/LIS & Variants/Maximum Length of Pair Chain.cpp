//Approach-1 (Using Simple LIS recursion+memo) - Since Qn asks to take pairs in any order, we sort it in the beginning
class Solution {
public:
    int n;
    int t[1001][1001];

    int solve(vector<vector<int>>& pairs, int idx, int prev) {
        if(idx == n) {
            return 0;
        }

        if(prev != -1 && t[idx][prev] != -1) {
            return t[idx][prev];
        }

        int take = 0;
        if(prev == -1 || pairs[idx][0] > pairs[prev][1]) {
            take = 1 + solve(pairs, idx+1, idx);
        }

        int skip = solve(pairs, idx+1, prev);

        if(prev != -1) {
            t[idx][prev] = max(take, skip);
        }

        return max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(t, -1, sizeof(t));
        return solve(pairs, 0, -1);
    }
};

//Approach-2 (Using Simple LIS Bottom Up)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<int> t(n, 1);

        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(pairs[i][0] > pairs[j][1]) {
                    t[i] = max(t[j]+1, t[i]);
                    maxL = max(maxL, t[i]);
                }
            }
        }

        return maxL;
    }
};
