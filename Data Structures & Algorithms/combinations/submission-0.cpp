class Solution {
   public:
    void solve(int i, int n, int k, vector<int>& dummy, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(dummy);
            return;
        }
        if (i > n) return;
        dummy.push_back(i);
        solve(i + 1, n, k -1, dummy, ans);
        dummy.pop_back();
        solve(i + 1, n, k, dummy, ans);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> dummy;
        solve(1, n, k, dummy, ans);
        return ans;
    }
};