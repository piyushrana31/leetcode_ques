class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        int i = 0;

        long long sum = 0;
        long long maxSum = 0;
        for(int j=0; j<n; j++) {
            sum += nums[j];
            freq[nums[j]]++;

            while(freq[nums[j]] > 1 || j-i+1 > k) {
                sum -= nums[i];
                freq[nums[i]]--;
                
                if(freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i++;
            }

            if(j-i+1 == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};