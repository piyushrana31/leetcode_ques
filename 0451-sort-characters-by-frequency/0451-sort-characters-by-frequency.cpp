bool compareValue(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}
class Solution {
public:

    string frequencySort(string s) {
        int n = s.size();

        vector<pair<char, int>> freq;
        sort(s.begin(), s.end());

        for(int i=0; i<n; i++) {
            int count1 = 1;
            while(i<n-1 && s[i+1] == s[i]) {
                count1++;
                i++;
            }

            freq.push_back({s[i], count1});
        }
        

        string ans = "";
        sort(freq.begin(), freq.end(), compareValue);

        for(auto pair : freq) {
            while(pair.second != 0) {
                ans += pair.first;
                pair.second--;
            }

        }

        return ans;
    }
};