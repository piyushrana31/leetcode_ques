class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int count = 0, l = 0, r = 0;
        int countA = 0, countB = 0, countC = 0;

        while(r < n) {
            if(s[r] == 'a') countA++;
            else if(s[r] == 'b') countB++;
            else countC++;

            while(countA >= 1 && countB >= 1 && countC >= 1) {
                count += (n-r);
                if(s[l] == 'a') countA--;
                else if(s[l] == 'b') countB--;
                else countC--;
                l++;
            }
            r++;
        }
        return count;
    }
};