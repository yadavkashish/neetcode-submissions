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
    void solve(int n, vector<string>& ans, string& dummy) {
        if (dummy.length() == n * 2 && isvalid(dummy)) {
            ans.push_back(dummy);
            return;
        }
       if(dummy.length() >= n * 2) return;
        dummy.push_back('(');
        solve(n, ans, dummy);
        dummy.pop_back();
        dummy.push_back(')');
        solve(n, ans, dummy);
        dummy.pop_back();
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string dummy;
        solve(n, ans, dummy);
        return ans;
    }
};
