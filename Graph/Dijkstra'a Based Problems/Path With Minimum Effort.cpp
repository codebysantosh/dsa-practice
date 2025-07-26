class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while(!pq.empty()) {

            int diff = pq.top().first;
            auto &curr = pq.top().second;
            int i = curr.first;
            int j = curr.second;

            pq.pop();

            //Why returning now ?
            //Because there is no way that the rest of elements can update the weight of destination cell even smaller due to the min heap.
            if(i == m-1 && j == n-1) {
                return diff;
            }

            for(auto &dir : directions) {

                int x = i+dir[0];
                int y = j+dir[1];

                if(isSafe(x, y)) {

                    int newdiff = max(diff ,abs(heights[i][j] - heights[x][y]));

                    if(newdiff < result[x][y]) {
                        result[x][y] = newdiff;
                        pq.push({newdiff, {x, y}});
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
};
