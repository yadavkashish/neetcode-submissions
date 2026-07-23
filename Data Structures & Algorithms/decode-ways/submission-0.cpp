class Solution {
public:
    int solve(string s, int i, vector<int>& dp) {
        if (i == s.size())
            return 1;
        if (i > s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        if (s[i] == '0')
            return 0;
        int num1 = 0;
        int num2 = 0;
        if ((i < s.size() - 1) &&
            ((s[i] == '2' && s[i + 1] <= '6') || (s[i] == '1'))) {
            num1 = solve(s, i + 2,dp);
        }
        num2 = solve(s, i + 1,dp);
        return dp[i]=num1 + num2;
    }
    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};