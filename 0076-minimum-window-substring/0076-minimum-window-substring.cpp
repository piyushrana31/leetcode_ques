class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int l = 0, r = 0, minLength = INT_MAX;
        int startIndex = -1, count = 0;

        unordered_map<char, int> mpp;
        for(int i=0; i<m; i++) {
            mpp[t[i]]++;
        }

        while(r < n) {
            if(mpp[s[r]] > 0) {
                count++;
            }
            mpp[s[r]]--;

            while(count == m) {
                if(r-l+1 < minLength) {
                    minLength = r-l+1;
                    startIndex = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) count--;
                l++;
            }

            r++;
        }
        return (startIndex==-1) ? "" : s.substr(startIndex, minLength);
    }
};