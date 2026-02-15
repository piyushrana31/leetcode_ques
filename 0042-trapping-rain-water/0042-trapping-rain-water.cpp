class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int lmax[n];
        lmax[0] = height[0];
        for(int i=1; i<n; i++) {
            lmax[i] = max(lmax[i-1], height[i]);
        }

        int rmax[n];
        rmax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            rmax[i] = max(rmax[i+1], height[i]);
        }

        int totalWater = 0;
        for(int i=0; i<n; i++) {
            totalWater += (min(rmax[i], lmax[i]) - height[i]);
        }

        return totalWater;
    }
};