class Solution {
public:
    int func1(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int n = nums.size();
        unordered_map<int, int> mpp;

        int l = 0, r = 0, ans = 0;
        while(r < n) {
            mpp[nums[r]]++;

            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            ans += (r-l+1);
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (func1(nums, k) - func1(nums, k-1));
    }
};