class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        if(s.size()==0) return 0;
        int maxi = INT_MIN;
        int cnt = 0;
        int r = 0;
        int l = 0;
        while (r < s.size()) {
            if (mp.count(s[r]) && mp[s[r]] >=l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]]=r;
            cnt = r - l + 1;
            maxi = max(maxi, cnt);
            r++;
        }
        return maxi;
    }
};
