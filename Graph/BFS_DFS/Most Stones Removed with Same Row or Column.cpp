//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    void dfs(vector<vector<int>>& stones, int idx, vector<bool> &visited) {
        visited[idx] = true;

        for(int i = 0; i<stones.size(); i++) {
            int r = stones[idx][0];
            int c = stones[idx][1];

            if((visited[i] == false) && (stones[i][0] == r || stones[i][1] == c)) {
                dfs(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool> visited(n, false);

        int group = 0;
        for(int i = 0; i<n; i++) {
            if(visited[i]) continue;

            dfs(stones, i, visited);
            group++;
        }

        return (n - group);
    }
};
