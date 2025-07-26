//Just copy paste the Dijkstra'a Code and Find the maximum amongst the minimums in result vector
//But, Why maximum ?
//Because, we have to return the minimum time it takes for all the n nodes to receive the signal
class Solution {
public:
    typedef pair<int, int> p;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<p>> adj;

        for(auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v, w});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> result(n+1, INT_MAX);

        pq.push({0, k});
        result[k] = 0;

        while(!pq.empty()) {

            int t = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto &vec : adj[node]) {

                int adjNode = vec.first;
                int time = vec.second;

                if(time+t < result[adjNode]) {
                    result[adjNode] = time+t;
                    pq.push({t+time, adjNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i<=n; i++) {
            if(result[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, result[i]);
        }

        return ans;
    }
};
