class Solution {
public:
void solve(int i,string s, unordered_set<string>&st,string dummy, vector<string>&ans){
    if(i==s.size()){
        ans.push_back(dummy);
        return;
    }
    if(i>s.size()) return;
    for(int j=i;j<s.size();j++){
        string word=s.substr(i,j-i+1);
        if(st.count(word)){
            string temp=dummy;
            if(!dummy.empty()) temp=temp+" ";
            temp=temp+word;
            solve(j+1,s,st,temp,ans);

            
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        string dummy;
        vector<string>ans;
        solve(0,s,st,dummy,ans);
        return ans;
    }
};