class Solution {
   public:
    int solve(vector<int>& prices, int i, int lastbuy,vector<vector<int>>&dp) {
        if (i >= prices.size()) return 0;
        if(dp[i][lastbuy+1]!=-1) return dp[i][lastbuy+1];
       
        if (lastbuy == -1) {
            int buy = solve(prices, i + 1, i,dp);
            int notbuy = solve(prices, i + 1, -1,dp);
            return dp[i][lastbuy+1]=max(buy, notbuy);
        } else if (lastbuy != -1) {
            if (prices[i] > prices[lastbuy]) {
               int sell = prices[i] - prices[lastbuy];
               int notsell = solve(prices, i + 1, lastbuy,dp);
                return  dp[i][lastbuy+1]= max(sell, notsell);
            } else {
                return dp[i][lastbuy+1]= solve(prices, i + 1, lastbuy,dp);
            }
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(prices.size()+1,-1));
        return solve(prices,0,-1,dp);
    }
};
