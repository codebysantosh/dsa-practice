//Approach - I (BF)
//T.C = O(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};

//Approach - II (Staircase search)
//T.C = O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n-1;
        while(i < m && j >= 0) {

            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
};

//Approach - III (Binary search)
//T.C = O(log(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end = m*n-1;
        while(st <= end) {

            int mid = st + (end - st)/2;

            int row = mid/n; //1-D to 2-D index
            int col = mid%n; //1-D to 2-D index

            if(matrix[row][col] < target) {
                st = mid+1;
            } else if(matrix[row][col] > target) {
                end = mid-1;
            } else {
                return true;
            }
        }

        return false;
    }
};
