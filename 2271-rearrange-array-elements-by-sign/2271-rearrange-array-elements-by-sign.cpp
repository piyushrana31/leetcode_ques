class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        vector<int> positive;
        vector<int> negative;

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                positive.push_back(nums[i]);
            }else{
                negative.push_back(nums[i]);
            }
        }

        int j=0;
        int k=0;
        for(int i=0; i<n; i++) {
            if(i%2==0) {
                ans.push_back(positive[j]);
                j++;
            }else {
                ans.push_back(negative[k]);
                k++;
            }
        }

        return ans;
    }
};