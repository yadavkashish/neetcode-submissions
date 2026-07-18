class Solution {
   public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& dummy) {
        if (i >= nums.size()) {
            ans.push_back(dummy);
            return;
        }
        dummy.push_back(nums[i]);
        solve(nums, i + 1, ans, dummy);
        dummy.pop_back();
       while(i<nums.size()-1&&nums[i]==nums[i+1]){
        i++;
       }
       solve(nums,i+1,ans,dummy);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> dummy;
        solve(nums, 0,ans, dummy);
        return ans;
    }
};
