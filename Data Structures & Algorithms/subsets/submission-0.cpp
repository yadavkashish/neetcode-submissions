class Solution {
public:
void solve(vector<int>& nums,int i, vector<vector<int>>&ans,vector<int>&dummy){
    if(i==nums.size()){
        ans.push_back(dummy);
        return;
    }
    solve(nums,i+1,ans,dummy);
    dummy.push_back(nums[i]);
    solve(nums,i+1,ans,dummy);
    dummy.pop_back();
    return;
}
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>dummy;
         solve(nums,0,ans,dummy);
         return ans;
    }
};
