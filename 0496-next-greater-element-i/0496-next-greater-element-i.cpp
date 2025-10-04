class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> mpp;
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();

            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(mpp[num]);
        }

        return ans;
    }
};