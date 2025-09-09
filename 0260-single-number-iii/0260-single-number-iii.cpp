class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i=0; i<n; i++) {
            res ^= nums[i];
        }

        int res1 = (unsigned int)res & -(unsigned int)res; // rightmost bit is masked

        int x=0;
        int y=0;
        for(int i=0; i<n; i++) {
            if(nums[i] & res1) {
                x ^= nums[i];
            } else {
                y ^= nums[i];
            }
        }
        return {x,y};
    }
};