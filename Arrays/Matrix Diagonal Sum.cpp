class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += mat[i][i];

            int j = n-i-1;
            if(j != i) {
                sum += mat[i][j];
            }
        }

        return sum;
    }
};
