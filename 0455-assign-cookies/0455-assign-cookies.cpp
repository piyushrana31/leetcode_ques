class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int g1 = g.size();
        int s1 = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int i=0;
        int j=0;
        while(i<g1 && j<s1) {
            if(s[j] >= g[i]) {
                ans++;
                i++;
                j++;
            }else {
                j++;
            }
        }

        return ans;
    }
};