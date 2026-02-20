class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(), strs.end());

        string ans = "";

        int mini = INT_MAX;
        int s1 = strs[0].size();
        int s2 = strs[n-1].size();

        mini = min(s1, s2);
        
        for(int i=0; i<mini; i++) {
            if(strs[0][i] == strs[n-1][i]) {
                ans += strs[0][i];
            }else {
                break;
            }
        }

        return ans;
    }
};  