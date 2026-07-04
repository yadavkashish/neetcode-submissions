class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
    unordered_map<int,int>mp;
    priority_queue<pair<int,int>> pq;
                       vector<int>ans;
     for(int i=0;i<nums.size();i++){
         mp[nums[i]]++;
     }
     
    for(auto i:mp){
       
        pq.push({i.second,i.first});
       
    }
    while(k){
        ans.push_back(pq.top().second);
        k--;
        pq.pop();
    }
     return ans;

    }
};
