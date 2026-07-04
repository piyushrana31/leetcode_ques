class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();

        if(s1 != t1) return false;

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for(int i=0; i<s1; i++) {
            if(freq1[s[i]] != freq2[t[i]]) return false;

            freq1[s[i]] = i+1;
            freq2[t[i]] = i+1;
        }

        return true;
    }
};