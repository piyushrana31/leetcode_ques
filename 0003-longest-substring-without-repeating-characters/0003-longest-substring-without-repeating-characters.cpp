class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mpp;

        int l = 0, r = 0;
        int len = 0;
        int maxLen = 0;
        while(r < n) {
            if(mpp.find(s[r]) != mpp.end()) {
                if(mpp[s[r]] >= l) {
                    l = mpp[s[r]] + 1;
                }
            }
            mpp[s[r]] = r;  
            len = r-l+1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
    }
};