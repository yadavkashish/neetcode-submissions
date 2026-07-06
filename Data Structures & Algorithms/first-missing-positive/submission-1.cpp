class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cnt = 1;
        int i = 0;
        sort(nums.begin(), nums.end());
        while (i < nums.size()) {
            if (nums[i] <= 0) {
                i++;
            } else if (cnt != nums[i]) {
                if(i>0 && nums[i-1]!=nums[i])
                return cnt;
                else
                i++;
            } else if (cnt == nums[i]) {
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};