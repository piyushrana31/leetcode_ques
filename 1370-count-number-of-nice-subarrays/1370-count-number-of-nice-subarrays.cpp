class Solution {
public:
    int func1(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int n = nums.size();

        int l = 0, r = 0, count = 0, ans = 0;

        while(r < n) {
            if(nums[r] % 2 == 1) count++;

            while(count > k) {
                if(nums[l] % 2 == 1) count--;
                l++;
            }
            ans += (r-l+1);

            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return (func1(nums, k) - func1(nums, k-1));
    }
};