class Solution {
public:
     int solve(int i,vector<int>& nums,int num){
        if(i>=nums.size()) return 0;
        int take=0;
        int nottake=0;
        if(nums[i]-num==1) {
            take=1+solve(i+1,nums,nums[i]);
        }
        nottake=solve(i+1,nums,num);
        return max(take,nottake);
     }
   
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        sort(nums.begin(),nums.end());

       vector<int>arr;
       arr.push_back(nums[0]);
       for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]) arr.push_back(nums[i]);
       }
       int maxi=INT_MIN;
       for(int i=0;i<arr.size();i++){
        int num=1+solve(1,arr,arr[i]);
        maxi=max(maxi,num);
        }
        return maxi;
    }
};
