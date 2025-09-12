class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> mpp;
        int l = 0, r = 0, maxFruits = 0;

        while(r < n) {
            mpp[fruits[r]]++;

            
            while(mpp.size() > 2) {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            maxFruits = max(maxFruits, r-l+1);
            r++;
        }
        return maxFruits;
    }
};