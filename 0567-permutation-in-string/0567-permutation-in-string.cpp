class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        unordered_map<char, int> freq;
        for(int i=0; i<n1; i++) {
            freq[s1[i]]++;
        }

        int i=0;
        int size = freq.size();
        for(int j=0; j<n2; j++)  {
            if(freq.find(s2[j]) != freq.end()) {
                freq[s2[j]]--;
                if(freq[s2[j]] == 0) size--;
                if(size == 0) {
                    return true;
                }
            }

            if(j-i+1 == n1) {
                if(freq.find(s2[i]) != freq.end()) {
                    if(freq[s2[i]] == 0) size++;
                    freq[s2[i]]++;
                }
                i++;
            }
        }

        return false;
    }
};