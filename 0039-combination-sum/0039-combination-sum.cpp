class Solution {
public:
    void lemmeCheck(int ind, vector<int> box, vector<int> &candidates, int target, int n, vector<vector<int>> &ans) {
        if(ind == n) {
            if(target == 0) {
                ans.push_back(box);
            }
            return;
        }

        if(target >= candidates[ind]) {
            box.push_back(candidates[ind]);
            lemmeCheck(ind, box, candidates, target-candidates[ind], n, ans);
            box.pop_back();
        }

        lemmeCheck(ind+1, box, candidates, target, n, ans);
    } 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> box;
        vector<vector<int>> ans;
        lemmeCheck(0, box, candidates, target, n, ans);

        return ans;
    }
};