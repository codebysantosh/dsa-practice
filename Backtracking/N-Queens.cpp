//Approach-1 (Simple dfs)
//T.C : O(N!)
//S.C : O(N)
class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string>& board, int r, int c) {

        //vertical
        for(int i = r; i >= 0; i--) {
            if(board[i][c] == 'Q') {
                return false;
            }
        }

        //diagonal left
        for(int i = r, j = c; i>= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        //diagonal right
        for(int i = r, j = c; i >= 0 && j<board.size(); i--, j++) {
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

        for(int c = 0; c < n; c++) {

            if(isSafe(board, r, c)) {
                board[r][c] = 'Q';
                solve(board, n, r+1);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        return result;
    }
};

//Approach-2
//T.C : O(N!) in worst case it explores all possible configurations
//S.C : O(N) for result and also for storing, cols, diags and antidiags
class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> col;
    unordered_set<int> diagonal;
    unordered_set<int> antiDiagonal;

    void solve(vector<string>& board, int n, int r) {
        if(r == n) {
            result.push_back(board);
            return;
        }

        /*
            For a square (i, j) :
            Diagonally (i-j)      is constant
            Anti diagonally (i+j) is constant
            
            We can use this to find which square(i, j)
            has a risk of being attacked by another queen
            placed already in 'diagonal', or 'anti-diagonal'
            or 'column'
        */

        for(int c = 0; c < n; c++) {

            int diagConst = r + c;
            int antidiagConst = r - c;

            if(col.find(c) != col.end() || diagonal.find(diagConst) != diagonal.end() || 
            antiDiagonal.find(antidiagConst) != antiDiagonal.end()) {
                continue;
            }

            col.insert(c);
            diagonal.insert(diagConst);
            antiDiagonal.insert(antidiagConst);
            board[r][c] = 'Q';

            solve(board, n, r+1);

            col.erase(c);
            diagonal.erase(diagConst);
            antiDiagonal.erase(antidiagConst);
            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        return result;
    }
};
