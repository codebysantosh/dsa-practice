//Approach-1 (Using Priority_queue and Adjacency list representation of graph) - Prim's Algorithm
typedef pair<int, int> P;
class Solution {
public:
    int minMST(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq; //minheap
        pq.push({0, 0}); //{weight, vertex}
        
        vector<bool> inMST(V, false);
        int sum = 0;
 
        while(!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt     = p.first;
            int node   = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; //added to mst
            sum += wt;
            
            for(auto &tmp : adj[node]) {
                
                int neighbor      = tmp.first;
                int neighbor_wt   = tmp.second;
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
 
            }
        }
        
        return sum;
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        
        vector<vector<P>> adj(V);
        
        for(int i = 0; i < V; i++) {
            for(int j = i+1; j<V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int d = abs(x1-x2) + abs(y1-y2);
                
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        
        return minMST(adj, V);
        
    }
};

//Approach-2 (Using Kruskal's Algorithm)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void unioon(int x, int y) {

        int px = find(x);
        int py = find(y);

        if(px == py) {
            return;
        }

        if(rank[px] > rank[py]) {
            parent[py] = px;
        } else if(rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }

    int kruskal(vector<vector<int>> &vec) {
        int sum = 0;

        for(auto &temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];

            if(find(u) != find(v)) {
                unioon(u, v);
                sum += w;
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i<V; i++) {
            parent[i] = i;
        }

        vector<vector<int>> vec;

        for(int i = 0; i<V; i++) {
            for(int j = i+1; j<V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                vec.push_back({i, j, dist});
            }
        }

        auto comparator = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };

        sort(begin(vec), end(vec), comparator);

        return kruskal(vec);
    }
};
