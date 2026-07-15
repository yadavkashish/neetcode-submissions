class Solution {
public:
void solve(vector<int>& nums, int target,int i, vector<vector<int>>& ans,vector<int>&temp){
    if(i>=nums.size()) return;
    if(target==0) 
    {ans.push_back(temp);
     return;}
     if(target<0) return;
     temp.push_back(nums[i]);
     solve(nums,target-nums[i],i,ans,temp);
     temp.pop_back();
     solve(nums,target,i+1,ans,temp);
     return;
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,target,0,ans,temp);
        return ans;
    }
};
