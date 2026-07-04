class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<numbers.size();i++){
            int t=target-numbers[i];
            if(mp.find(t)!=mp.end()){
                ans.push_back(mp[t]+1);
                ans.push_back(i+1);
                return ans;
            }
            else{
                mp[numbers[i]]=i;
            }
        }
        return ans;
    }
};
