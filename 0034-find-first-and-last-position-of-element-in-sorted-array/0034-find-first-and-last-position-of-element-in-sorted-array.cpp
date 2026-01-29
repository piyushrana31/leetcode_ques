class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int start = -1;
        int end = -1; 

        if(n==0) return {-1, -1};

        start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(start == n || nums[start] != target) {
            return {-1, -1};
        }

        return {start, end-1};
    }
};