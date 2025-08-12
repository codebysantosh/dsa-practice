//T.C : O(3^(n^2))
//S.C : O(L * X) - L = Length of path, X = number of paths
class Solution {
  public:
    int m;
    vector<string> result;
    
    bool isSafe(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < m); 
    }
    
    void solve(vector<vector<int>> &maze, int i, int j, string &temp) {
        if(!isSafe(i, j) || maze[i][j] == 0) {
            return;
        }
        
        if(i == m-1 && j == m-1) {
            result.push_back(temp);
            return;
        }
        
        maze[i][j] = 0;
        
        //down
        temp.push_back('D');
        solve(maze, i+1, j, temp);
        temp.pop_back();
        
        //left
        temp.push_back('L');
        solve(maze, i, j-1, temp);
        temp.pop_back();
        
        //right
        temp.push_back('R');
        solve(maze, i, j+1, temp);
        temp.pop_back();
        
        //up
        temp.push_back('U');
        solve(maze, i-1, j, temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        m = maze.size();
        
        if(maze[0][0] == 0) {
            return {};
        }
        
        string temp = "";
        solve(maze, 0, 0, temp);
        
        return result;
    }
};
