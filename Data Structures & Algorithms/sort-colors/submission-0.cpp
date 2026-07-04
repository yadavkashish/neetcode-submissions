class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int> cnt(3,0);
       for(int i=0;i<nums.size();i++){
        cnt[nums[i]]++;
       }
       nums.clear();
      for(int i=0;i<cnt.size();i++){
        while(cnt[i]>0){
           nums.push_back(i);
           cnt[i]--;
        }
      }
      return;
    }
};