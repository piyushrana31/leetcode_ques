class Solution {
public:
    int func1(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.size();

        int l = 0, r = 0, sum = 0;
        int ans = 0;
        while(r < n) {
            sum += nums[r];

            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            ans += (r-l+1);

            r++;

        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (func1(nums, goal) - func1(nums, goal-1));
    }
};