//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int u) {
        queue<int> q;
        q.push(u);

        unordered_map<int, bool> visited;
        visited[u] = true;

        int farthestNode = u;
        int dist = 0;

        while(!q.empty()) {

            int N = q.size();

            while(N--) {

                int u = q.front();
                q.pop();

                farthestNode = u;

                for(auto &v : adj[u]) {
                    if(!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }

            if(!q.empty()) dist++;
        }

        return {farthestNode, dist};
    }

    int findDiameter(unordered_map<int, vector<int>> &adj) {
        //step - 1 find the farthestNode from from a random node - 0
        auto [farthestNode, dist] = BFS(adj, 0);

        //step - 2 the farthestNode we got above is nothing but one end of the diameter of adj

        //step - 3 find the otherFarthestNode from the node we got above , that will be the other end of the diameter 
        auto [otherendfarthestNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> makeadj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        unordered_map<int, vector<int>> adj1 = makeadj(edges1);
        unordered_map<int, vector<int>> adj2 = makeadj(edges2);
        
        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int result = (d1+1)/2 + (d2+1)/2 + 1;
        
        return max({result, d1, d2});
    }
};
