class Solution {
public:
   bool solve(string &s, int i,int j){
    if(s[i]!=s[j]) return false;
    if(i>=j) return true;
     return solve(s,i+1,j-1);
   }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(solve(s,i+1,j)) return true;
                if(solve(s,i,j-1)) return true;
                return false;
            }
        }
        return true;
    }
};