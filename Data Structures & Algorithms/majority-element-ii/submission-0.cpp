class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int times = nums.size() / 3;
        unordered_map<int, int> fr;
        for (int i = 0; i < nums.size(); i++) {
            fr[nums[i]]++;
        }
        vector<int> ans;
        for (auto i : fr) {
            if (i.second > times) ans.push_back(i.first);
        }
        return ans;
    }
};