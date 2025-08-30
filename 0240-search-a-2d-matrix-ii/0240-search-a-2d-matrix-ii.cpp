class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++) {
            int last = matrix[i][n-1];

            if(last < target) {
                continue;
            }else {
                for(int j=0; j<n; j++) {
                    if(matrix[i][j] == target) return true;
                }
            }
        }
        return false;
    }
};