class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int majorityEle = nums[0];

        for(int i=0; i<n; i++) {
            if(count==0) {
                majorityEle = nums[i];
                count=1;
            }else if(majorityEle == nums[i]) {
                count++;
            }else{
                count--;
            }
        }

        return majorityEle;
    }
};