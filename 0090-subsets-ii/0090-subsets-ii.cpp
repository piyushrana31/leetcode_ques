class Solution {
public:
    void uniqueSubsets(int ind, vector<int> box, vector<int> &nums, vector<vector<int>> &ans, int n) {
        ans.push_back(box);
        
        for(int i=ind; i<n; i++) {
            if(i > ind && nums[i] == nums[i-1]) continue;

            box.push_back(nums[i]);
            uniqueSubsets(i+1, box, nums, ans, n);
            box.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> box;
        vector<vector<int>> ans;

        uniqueSubsets(0, box, nums, ans, n);

        return ans;
    }
};