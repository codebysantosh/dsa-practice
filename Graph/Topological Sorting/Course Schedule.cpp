//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int V, vector<int>& indegree) {
        queue<int> q;

        int count = 0;
        for(int i = 0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int &v : adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        if(count == V) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<int> indegree(numCourses, 0); //kahn's algo

        for(auto vec : prerequisites) {

            int v = vec[0];
            int u = vec[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        //if cycle is present, not possible

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

//Approach-2 (Using DFS Cycle Check)
class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool> &inRecu) {
        visited[u] = true;
        inRecu[u]  = true;

        for(auto &v : adj[u]) {
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecu)) {
                return true;
            } else if(inRecu[v] == true) {
                return true;
            }
        }

        inRecu[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto vec : prerequisites) {

            int v = vec[0];
            int u = vec[1];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecu(numCourses, false);

        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecu)) {
                return false;
            }
        }

        return true;
    }
};
