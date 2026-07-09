class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> pre;
        vector<int> suff(height.size());
        int maxi = INT_MIN;
        int maxi2=INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            maxi = max(maxi, height[i]);
            pre.push_back(maxi);
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            maxi2 = max(maxi2, height[i]);
            suff[i] = maxi2;
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
          
                if (height[i] < pre[i] && height[i] < suff[i]) {
                    ans = ans + min(pre[i], suff[i]) - height[i];
                }
            
        }
        return ans;
    }
};
