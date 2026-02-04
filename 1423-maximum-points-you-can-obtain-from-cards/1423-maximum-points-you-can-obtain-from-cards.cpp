class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int j=n-1;

        int lSum = 0;
        int rSum = 0;


        for(int p=0; p<k; p++) {
            lSum += cardPoints[p];
        }
        int maxSum = lSum;

        for(int it=k-1; it>=0; it--) {
            lSum -= cardPoints[it];
            rSum += cardPoints[j];
            j--;

            maxSum = max(maxSum, lSum + rSum);
        }

        return maxSum;
    }
};