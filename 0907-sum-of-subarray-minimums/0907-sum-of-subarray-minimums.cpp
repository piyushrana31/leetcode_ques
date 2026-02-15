class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
    }

    vector<int> nextPrevSmallerOrEqualElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> npsee(n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            npsee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return npsee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = nextSmallerElement(arr);
        vector<int> npsee = nextPrevSmallerOrEqualElement(arr);

        int left = 0;
        int right = 0;
        int total = 0;
        int mod = (int)(1e9 + 7);

        for(int i=0; i<n; i++) {
            left = i - npsee[i];
            right = nse[i] - i;

            total = (total + (left*right*1LL*arr[i])%mod)%mod;
        }

        return total;
    }
};