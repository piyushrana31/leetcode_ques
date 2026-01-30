class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int n = nums.size();

        int count = 1;
        int last = 0;

        for(int i=0; i<n; i++) {
            if(last + nums[i] <= mid) {
                last += nums[i];
            }else {
                count++;
                last = nums[i];
            }

            if(count > k) return false;
        }

        return true;
    } 

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return ans;
    }
};