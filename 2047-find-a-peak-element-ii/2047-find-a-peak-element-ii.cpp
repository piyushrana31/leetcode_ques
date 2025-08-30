class Solution {
public:
    int findMaxElement(vector<vector<int>>& mat, int m, int n, int col) {
        int maxi = -1;
        int index = -1;

        for(int i=0; i<m; i++) {
            if(mat[i][col] > maxi) {
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int maxRowIndex = findMaxElement(mat, m, n, mid);
            int left = (mid-1>=0) ? mat[maxRowIndex][mid-1] : -1;
            int right = (mid+1<n) ? mat[maxRowIndex][mid+1] : -1;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
                return {maxRowIndex, mid};
            }else if(mat[maxRowIndex][mid] < left) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};