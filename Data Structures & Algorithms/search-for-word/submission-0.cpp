class Solution {
   public:
    bool solve(vector<vector<char>>& board, int i, int j, int ind, vector<vector<int>>& v,
               string word) {
        if (ind == word.size()) return true;
        if (i >= board.size() || j >= board[0].size()||i<0||j<0) return false;
        if (v[i][j]) return false;
        if (board[i][j] != word[ind]) return false;
        v[i][j] = 1;
        bool found =
            solve(board, i + 1, j, ind + 1, v, word) || solve(board, i - 1, j, ind + 1, v, word) ||
            solve(board, i, j - 1, ind + 1, v, word) || solve(board, i, j + 1, ind + 1, v, word);

        v[i][j] = 0;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> v(board.size(), vector<int>(board[0].size(), 0));
         for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(board, i, j, 0, v, word))
                    return true;
            }
        }

        return false;
       
    }
};
