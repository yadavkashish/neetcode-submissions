class Solution {
public:

int solve(vector<int>& cost,vector<int>&dp,int i){
    if(i==cost.size()) return 0;
    if(i>cost.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int one=cost[i]+solve(cost,dp,i+1);
    int two=cost[i]+solve(cost,dp,i+2);
    return dp[i]= min(one,two);
}
   

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        int num1=solve(cost,dp,0);
        int num2=solve(cost,dp,1);
        return min(num1,num2);
    }
};
