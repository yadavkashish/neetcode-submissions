class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int l;
        int r;
        int i=0;
        while (i < s.size()) {
            cnt++;
            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
            i++;
        }
        int le;
        int re;
        int j=0;
        while (j < s.size()) {

            le = j;
            re = j + 1;
            while (le >= 0 && re < s.size() && s[le] == s[re]) {
                cnt++;
                le--;
                re++;
            }
            j++;
        }
        return cnt;
    }
};