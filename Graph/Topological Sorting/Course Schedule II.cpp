//Approach-1 (Using BFS Topological Sort Concept)
class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int V, vector<int>& indegree) {
        queue<int> q;
        vector<int> result;

        for(int i = 0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                result.push_back(i);
            }
        }

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(auto &v : adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                    result.push_back(v);
                }
            }
        }

        if(result.size() == V) {
            return result;
        }

        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree); 
    }
};

//Approach-2 (Using DFS)
class Solution {
public:
    bool hasCycle = false;

    void isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecu, stack<int>& st) {
        visited[u] = true;
        inRecu[u]  = true;

        for(auto &v : adj[u]) {
            if(inRecu[v] == true) {
                hasCycle = true;
                return;
            }
            
	        if(!visited[v])
	            isCycleDFS(adj, v, visited, inRecu, st);
        }

        st.push(u);
        inRecu[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecu(numCourses, false);
        stack<int> st;

        for(int i = 0; i<numCourses; i++) {
            if(!visited[i]) {
                isCycleDFS(adj, i, visited, inRecu, st);
            }   
        }

        vector<int> result;

        if(hasCycle) {
            return {};
        }

        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};
