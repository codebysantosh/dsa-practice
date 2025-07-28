//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        // Number of nodes in the tree
        int n = edges.size() + 1;

        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Find the diameter of the tree
        return findDiameter(n, adj);
    }

private:
    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, unordered_map<int, vector<int>>& adj) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adj, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adj, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the source
    pair<int, int> findFarthestNode(int n, unordered_map<int, vector<int>>& adj, int sourceNode) {
        queue<int> que;
        vector<bool> visited(n, false);

        // Push source node into the queue
        que.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0;
        int farthestNode = sourceNode;

        // Explore neighbors
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = que.front();
                que.pop();
                // Update farthest node
                farthestNode = currentNode;

                for (int neighbor : adj[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }
            if (!que.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};
