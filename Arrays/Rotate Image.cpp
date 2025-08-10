//T.C = O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //transpose
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        //reverse 
        int row = 0;   
        while(row < n) {
            int st = 0, end = n-1;

            while(st < end) {
                
                swap(matrix[row][st], matrix[row][end]);

                st++;
                end--;
            }
            row++;
        }
    }
};
