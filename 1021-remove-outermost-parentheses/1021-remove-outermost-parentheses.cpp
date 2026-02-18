class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        char a1 = '(';
        char a2 = ')';

        int count = 0;
        string ans = "";
        for(int i=0; i<n; i++) {
            if(s[i] == a1) {
                if(count > 0) {
                    ans += s[i];
                }

                count++;
            }else {
                count--;

                if(count > 0) {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};