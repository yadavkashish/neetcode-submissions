class Solution {
public:
int solve(int n,vector<int>&dp,int i){
    if(i==n) return 1;
    if(i>n) return 0;
    if(dp[i]!=-1) return dp[i];
    int one=solve(n,dp,i+1);
    int two=solve(n,dp,i+2);
    return dp[i]=one+two;
}
    int climbStairs(int n) {
        vector<int>dp(n,-1);
       return solve(n,dp,0);
    }
};
