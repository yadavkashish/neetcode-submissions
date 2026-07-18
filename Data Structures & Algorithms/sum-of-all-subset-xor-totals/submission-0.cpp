class Solution {
public:
int ans=0;
int solve(vector<int>& nums, int i, int sum){
    if(i==nums.size()){
        ans=ans+sum;
        return ans;
    }
    solve(nums,i+1,sum^nums[i]);
    solve(nums,i+1,sum);
    return ans;
}
    int subsetXORSum(vector<int>& nums) {
      solve(nums,0,0);
      return ans;
    }
};