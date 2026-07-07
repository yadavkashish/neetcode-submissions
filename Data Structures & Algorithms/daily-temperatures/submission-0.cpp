class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        st.push({temperatures[n - 1], n - 1});
        int j = n - 2;
        while (j >= 0) {
            while (!st.empty() && st.top().first <=temperatures[j]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[j] = st.top().second - j;
            }
            st.push({temperatures[j], j});
            j--;
        }
        return ans;
    }
};
