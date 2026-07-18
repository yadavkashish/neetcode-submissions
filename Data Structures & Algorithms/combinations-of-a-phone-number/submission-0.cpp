class Solution {
   public:
    void solve(string digits, int ind, string &s, vector<string>& ans,
               unordered_map<int, string>& mp) {
        if (ind >= digits.size()) {
            ans.push_back(s);
            return;
        }
        int num = digits[ind] - '0';
        string st = mp[num];
        for (int i = 0; i < st.size(); i++) {
            s.push_back(st[i]);
            solve(digits, ind + 1, s, ans, mp);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<int ,string> mp = {
            {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
        };
        vector<string> ans;
        string s;
        solve(digits, 0,s, ans,mp);
        return ans;
    }
};
