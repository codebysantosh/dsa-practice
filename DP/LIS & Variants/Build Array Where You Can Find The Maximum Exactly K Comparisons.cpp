//Approach-1 (Using Recursion + Memoization)
//T.C : O(m*n*k)
class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int t[51][51][101];

    int solve(int idx, int maxVal, int search_cost) {
        if(idx == N) {
            if(search_cost == K) {
                return 1;
            }
            return 0;
        }

        if(t[idx][search_cost][maxVal] != -1) {
            return t[idx][search_cost][maxVal];
        }

        int result = 0;

        for(int i = 1; i<=M; i++) {
            if(i > maxVal) {
                result = (result + solve(idx+1, i, search_cost+1)) % MOD;
            } else {
                result = (result + solve(idx+1, maxVal, search_cost)) % MOD;
            }
        }

        return t[idx][search_cost][maxVal] = result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;

        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
    }
};

//Approach-2 (Bottom Up)
//T.C : O(NKM^2)
