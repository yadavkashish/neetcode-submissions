class Solution {
   public:
    bool solve(int i, vector<int>& sq, vector<int>& matchsticks, int target) {
        if (i > matchsticks.size()) return false;
        if (i == matchsticks.size()) {
            for (int i = 0; i < 4; i++) {
                if (sq[i] != target) return false;
            }
            return true;
        }
        for (int j = 0; j < 4; j++) {
            if (matchsticks[i] + sq[j] > target) continue;
            sq[j] = sq[j] + matchsticks[i];
            if (solve(i + 1, sq, matchsticks, target)) return true;
            sq[j] = sq[j] - matchsticks[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum = sum + matchsticks[i];
        }
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        vector<int> sq(4, 0);
        return solve(0, sq, matchsticks, target);
    }
};