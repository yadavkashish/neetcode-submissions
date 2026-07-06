class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i,j;
        for(i=0,j=0;i<word1.size() && j<word2.size();i++,j++){
            
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
        }
        if(i!=word1.size()){
            while(i<word1.size()){
                ans.push_back(word1[i]);
                i++;
            }
        }
        else if(j!=word2.size()){
             while(j<word2.size()){
                 ans.push_back(word2[j]);
                j++;
             }
        }
        return ans;
    }
};