class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;

        for(int i=0; i<n; i++) {
            while((!st.empty() && st.top() > num[i]) && k>0) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(!st.empty() && k>0) {
            st.pop();
            k--;
        }

        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }


        reverse(str.begin(), str.end());

        int i=0;
        while(i < str.size() && str[i] == '0') i++;

        str = str.substr(i);

        return str.empty() ? "0" : str;
    } 
};