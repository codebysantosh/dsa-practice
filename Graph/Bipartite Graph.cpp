//Approach-1 (Graph coloring : DFS)
class Solution {
  public:
    bool dfs(unordered_map<int, vector<int>>& adj, int curr, vector<int> &color, int currColor) {
        color[curr] = currColor; //color kardiya curr node ko

        //ab jaate hain adjacent nodes par
        for(auto &v : adj[curr]) {
            if(color[v] == color[curr]) {
                return false;
            }
            
            if(color[v] == -1) { //never colored (never visited)
                int colorV = 1 - currColor;
                if(dfs(adj, v, color, colorV) == false) {
                    return false;
                }
            }
        }
        
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            int a = vec[0];
            int b = vec[1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> color(V, -1);

        //red = 1
	      //gree = 0
        
        for(int i = 0; i<V; i++) {
            if(color[i] == -1) {
                if(dfs(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

//Approach-2 (Graph coloring : BFS)
class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor) {
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(auto &v : graph[u]) {
                if(color[v] == color[u]){
                    return false;
                } else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i<n; i++) {
            if(color[i] == -1) {
                if(bfs(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
