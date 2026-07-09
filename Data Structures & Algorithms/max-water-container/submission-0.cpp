class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxi=INT_MIN;
        int num=0;
        while(i<j){
            num=min(heights[i],heights[j])*(j-i);
            maxi=max(maxi,num);
            if(heights[i]>heights[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;

    }
};
