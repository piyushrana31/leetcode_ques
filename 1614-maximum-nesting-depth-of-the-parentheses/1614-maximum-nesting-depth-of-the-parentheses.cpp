class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        
        int count = 0;
        int maxCount = 0;

        stack<int> st;
        char a1 = '(';
        char a2 = ')';

        for(int i=0; i<n; i++) {
            if(s[i] == a1) {
                st.push(a1);
                count++;
                maxCount = max(maxCount, count);
            }else if(s[i] == a2) {
                count--;
                st.pop();
            }
        }

        return maxCount;
    }
};