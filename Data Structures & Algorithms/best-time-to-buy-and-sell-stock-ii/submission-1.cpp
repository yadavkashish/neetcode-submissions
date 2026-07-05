class Solution {
   public:
    int solve(vector<int>& prices, int i, int lastbuy,vector<vector<int>>&dp) {
        if (i >= prices.size()) return 0;
          if(dp[i][lastbuy+1]!=-1) return dp[i][lastbuy+1];
          int ans=0;
        if (lastbuy == -1) {
            int buy = solve(prices, i + 1, i,dp);
            int notbuy = solve(prices, i + 1, -1,dp);
            ans=max(buy, notbuy);
        } else
          { if (prices[lastbuy] < prices[i]) {
            int sell = prices[i] - prices[lastbuy] + solve(prices, i + 1, -1,dp);
            int notsell = solve(prices, i + 1, lastbuy,dp);
            ans= max(sell, notsell);}
            else{
                ans=solve(prices,i+1,lastbuy,dp);
            }
        }

        return dp[i][lastbuy+1]=ans;
    }
    int maxProfit(vector<int>& prices) {
           vector<vector<int>>dp(prices.size(),vector<int>(prices.size()+1,-1));
        return solve(prices,0,-1,dp);
    }
};