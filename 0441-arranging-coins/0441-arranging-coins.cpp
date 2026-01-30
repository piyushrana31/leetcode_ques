class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1;
        long long high = n;
        int ans = -1;

        if(n==1) return 1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            long long sum = mid * (mid + 1) / 2;

            if(sum > n) {
                high = mid - 1;
            }else {
                ans = mid;
                low = mid + 1;
            }
        }

        return ans;
    }
};