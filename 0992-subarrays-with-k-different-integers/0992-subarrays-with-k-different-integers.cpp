class Solution {
public:
    int func(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0;
        
        int count = 0;
        unordered_map<int, int> mpp;

        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;

            while(mpp.size() > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            count += (j-i+1);
        } 
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};