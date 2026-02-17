class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& matrix) {
        int n = matrix.size();
        
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && matrix[st.top()] >= matrix[i]) st.pop();

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& matrix) {
        int n = matrix.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && matrix[st.top()] > matrix[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        
        return ans;
    }

    int maxAreaInSimpleArray(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        vector<int> nse = nextSmallerElement(nums);
        vector<int> pse = prevSmallerElement(nums);
        int area = 0;
        int maxArea = 0;

        for(int i=0; i<n; i++) {
            area = (nse[i] - pse[i] - 1) * nums[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        int area = 0;
        int maxArea = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            area = maxAreaInSimpleArray(height);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};