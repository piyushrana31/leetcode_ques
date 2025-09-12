class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mpp;

        int l = 0, r = 0, maxLength = 0, maxFreq = 0;
        while(r < n) {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

            int change = (r-l+1) - maxFreq;
            if(change > k) {
                mpp[s[l]]--;
                l++;
            }

            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};