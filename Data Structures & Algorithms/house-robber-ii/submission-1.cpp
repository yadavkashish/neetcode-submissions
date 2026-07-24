class Solution {
public:
    int solve(vector<int>& nums,int i, vector<int>&dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+solve(nums,i+2,dp,n);
        int nottake=solve(nums,i+1,dp,n);
        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(solve(nums,0,dp,n-1),solve(nums,1,dp2,n));
    }
};
