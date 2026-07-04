class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            unordered_map<int,int>mp;
            for(int j=0;j<board[0].size();j++){
                  if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    mp[num]++;
                    if(mp[num]>1) return false;
                  }
            }
        }

         for(int i=0;i<board[0].size();i++){
            unordered_map<int,int>mp;
            for(int j=0;j<board.size();j++){
                  if(board[j][i]!='.'){
                    int num=board[j][i]-'0';
                    mp[num]++;
                    if(mp[num]>1) return false;
                  }
            }
        }

        for(int row=0;row<board.size();row=row+3){
            for(int col=0;col<board[0].size();col=col+3){
                unordered_map<int,int>mp;
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                         if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    mp[num]++;
                    if(mp[num]>1) return false;
                  }
                    }
                }
            }
        }
        return true;
    }
};
