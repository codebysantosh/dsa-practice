//Approach-1 (Simple dfs)
//T.C : O(N!)
//S.C : O(N)
class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string> &board, int r, int c) {
        //virtical
        for(int i = r; i >=0; i--) {
            if(board[i][c] == 'Q') {
                return false;
            }
        }

        //diagonal-right
        for(int i = r, j = c; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        //diagonal-left
        for(int i = r, j = c; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, int n, int r) {
        if(r == n) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++) {

            if(isSafe(board, r, col)) {
                board[r][col] = 'Q';
                solve(board, n, r+1);
                board[r][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        return result;
    }
};
