class Solution {
public:

    bool solution(int r, int c, int m, int n, vector<vector<char>>& board, string word, int k){
        if(k >= word.size())
            return true;

        if(word.size() == 1 && word[k] == board[r][c])
            return true;

        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '.')
            return false;

        if(word[k] != board[r][c])
            return false;
     
        board[r][c] = '.';
        int a[4] = {1, -1, 0, 0};
        int b[4] = {0, 0, 1, -1};

        for(int i=0;i<4;i++){
            if(solution(r+a[i], c+b[i], m, n, board, word, k+1))
                return true;
        }

        board[r][c] = word[k];
        return false;        
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(solution(i, j, m, n, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
