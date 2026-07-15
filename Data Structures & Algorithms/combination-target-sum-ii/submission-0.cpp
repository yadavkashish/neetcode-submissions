class Solution {
   public:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans,
               vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size()) return;

        if (target < 0) return;
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, ans, temp);
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        temp.pop_back();
        solve(candidates, target, i + 1, ans, temp);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, ans, temp);
        return ans;
    }
};
