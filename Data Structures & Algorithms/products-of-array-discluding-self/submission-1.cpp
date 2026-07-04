class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        vector<int>prefix;
        vector<int>suffix;
        vector<int>ans;
         int p=1;
        for(int i=0;i<nums.size();i++){
            p=p*nums[i];
            prefix.push_back(p);
        }
        p=1;
       for(int i=nums.size()-1;i>=0;i--){
            p=p*nums[i];
            suffix.push_back(p);
       }
       int k=0;
       int l=suffix.size()-1;
     while(k<=l){
            swap(suffix[k],suffix[l]);
            k++;
            l--;
     }

       for(int i=0;i<nums.size();i++){
        if(i==0)ans.push_back(suffix[1]);
        else if(i==nums.size()-1) ans.push_back(prefix[i-1]);
        else{

        int val= prefix[i-1]*suffix[i+1];
        ans.push_back(val);
        }
       }
        return ans;
    }
};
