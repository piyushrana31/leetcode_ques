class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int i=0;
        int j=0;

        unordered_map<char, int> mpp;
        int maxLen = 0;

        while(j<n) {
            if(mpp.find(s[j]) != mpp.end()) {
                if(mpp[s[j]] >= i) i = mpp[s[j]] + 1;
            }
            mpp[s[j]] = j;
            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }
};