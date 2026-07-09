class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixsum(nums.size());
        prefixsum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixsum[i] = nums[i] + prefixsum[i - 1];
        }
        int cnt = 0;
        if (prefixsum[0] == k) cnt++;
        for (int j = 1; j < nums.size(); j++) {
            if (prefixsum[j] == k) {
                cnt++;
               
            }
            int target = prefixsum[j] - k;
            for (int i = 0; i < j; i++) {
                if (prefixsum[i] == target) cnt++;
            }
        }
        return cnt;
    }
};