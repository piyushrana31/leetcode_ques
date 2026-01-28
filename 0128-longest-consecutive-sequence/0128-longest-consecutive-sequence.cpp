class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        if(n==0) return 0;

        int maxCount = 1;
        for(auto it: st) {
            if(st.find(it-1) == st.end()) {
                int count=1;
                int x = it;
                while(st.find(x+1) != st.end()) {
                    count++;
                    maxCount = max(maxCount, count);
                    x++;
                }
            }
        }

        return maxCount;
    }
};