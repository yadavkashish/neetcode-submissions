class Solution {
   public:
    bool isvalid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') st.push(ch);
            if (ch == ')') {
                if (st.empty()) return false;
                st.pop();
            }
        }
        if (!st.empty()) return false;
        return true;
    }
    void solve(int n, int open, int close, vector<string>& ans, string& dummy) {
        if (dummy.length() == n * 2 && isvalid(dummy)) {
            ans.push_back(dummy);
            return;
        }
        if (dummy.length() >= n * 2) return;
        if (open < n) {
            dummy.push_back('(');
            solve(n, open + 1, close, ans, dummy);
            dummy.pop_back();
        }
        if (close < open) {
            dummy.push_back(')');
            solve(n,open,close+1,ans, dummy);
            dummy.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string dummy;
        solve(n,0,0, ans, dummy);
        return ans;
    }
};
