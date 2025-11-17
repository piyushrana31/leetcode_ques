class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int el1 = nums[0], el2 = nums[0];
        int count1 = 0, count2 = 0;

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(count1==0 && nums[i] != el2) {
                count1 = 1;
                el1 = nums[i];
            } else if(count2 == 0 && nums[i] != el1) {
                count2 = 1;
                el2 = nums[i];
            } else if(el1 == nums[i]) {
                count1++;
            } else if(el2 == nums[i]) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == el1) count1++;
            else if(nums[i] == el2) count2++;
        }

        if(count1 > n/3) ans.push_back(el1);
        if(count2 > n/3) ans.push_back(el2);

        return ans;

    }
};