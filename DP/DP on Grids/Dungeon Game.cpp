//Approach-1 - Brute Force (Binary Search on Answer) and also memoizing it - TLE
//T.C : O(O(log(maxHealth) * m * n * maxHealth), total states in map = m * n * maxHealth
//S.C : O(m * n * maxHealth)
class Solution {
public:
    int m, n;
    unordered_map<string, bool> mp;

    bool canSurvive(int i, int j, int currHealth, vector<vector<int>>& dungeon) {
        if(i >= m || j >= n) return false;

        currHealth += dungeon[i][j];
        if(currHealth <= 0) return false;

        if(i == m-1 && j == n-1) {
            return true;
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(currHealth);
        if(mp.count(key)) {
            return mp[key];
        }

        return mp[key] = canSurvive(i+1, j, currHealth, dungeon) || canSurvive(i, j+1, currHealth, dungeon);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        int minHealth = 1e7;
        int left = 1;
        int right = 1e7;

        while(left <= right) {
            int mid = left + (right-left)/2;

            mp.clear();  // clear for new health level

            if(canSurvive(0, 0, mid, dungeon)) {
                minHealth = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return minHealth;
    }
};

//Approach-2 (Using Recursion and Memoization) - ACCEPTED
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    int t[201][201];

    int solve(int i, int j, vector<vector<int>>& dungeon) {
        if (i >= m || j >= n)
            return 1e9;

        if (t[i][j] != -1)
            return t[i][j];

        if (i == m - 1 && j == n - 1)
            return t[i][j] = (dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1);

        int down  = solve(i + 1, j, dungeon);
        int right = solve(i, j + 1, dungeon);

        int res = min(down, right) - dungeon[i][j];
        return t[i][j] = (res > 0 ? res : 1);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, dungeon);
    }
};

//Approach-3 (Bottom Up) - ACCEPTED
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        //NOTE : We will write bottom up by traversing from bottom right to top left because 
        // when we find t[i][j] we must be already aware of the health for down (t[i+1][j) and right (t[i][j+1])

        vector<vector<int>> t(m, vector<int> (n));
        //t[i][j] = min health needed to reach (m-1, n-1) from (i,j)

        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {

                if(i == m-1 && j == n-1) {
                    t[i][j] = dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1; 
                } else {
                    int right = (j+1 >= n) ? 1e9 : t[i][j+1];
                    int down  = (i+1 >= m) ? 1e9 : t[i+1][j];

                    int result = min(right, down) - dungeon[i][j];

                    t[i][j] = (result > 0) ? result : 1;
                }
            }
        }

        return t[0][0]; //min Health required to reach (m-1,n-1) from (0, 0)
    }
};
