class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){                
                if(board[i][j] == '.')
                    continue;
                for(int a = i+1;a<board.size();a++){
                    if(board[i][j] == board[a][j])
                        return false;
                }
                for(int a = j+1;a<board.size();a++){
                    if(board[i][j] == board[i][a])
                        return false;    
                }
            }
        }
        unordered_map<int, unordered_map<int, int>> m;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.')
                    continue;
                if(i < 3){
                    if(j < 3){
                        if(m[1].find(board[i][j]) != m[1].end())
                            return false;
                        m[1].insert({board[i][j],0});
                    }
                    else if(j<6){
                        if(m[2].find(board[i][j]) != m[1].end())
                            return false;
                        m[2].insert({board[i][j],0});
                    }
                    else{
                        if(m[3].find(board[i][j]) != m[1].end())
                            return false;
                        m[3].insert({board[i][j],0});
                    }
                }
                else if(i < 6){
                    if(j < 3){
                        if(m[4].find(board[i][j]) != m[1].end())
                            return false;
                        m[4].insert({board[i][j],0});
                    }
                    else if(j<6){
                        if(m[5].find(board[i][j]) != m[1].end())
                            return false;
                        m[5].insert({board[i][j],0});
                    }
                    else{
                        if(m[6].find(board[i][j]) != m[1].end())
                            return false;
                        m[6].insert({board[i][j],0});
                    }
                }
                else {
                    if(j < 3){
                        if(m[7].find(board[i][j]) != m[1].end())
                            return false;
                        m[7].insert({board[i][j],0});
                    }
                    else if(j<6){
                        if(m[8].find(board[i][j]) != m[1].end())
                            return false;
                        m[8].insert({board[i][j],0});
                    }
                    else{
                        if(m[9].find(board[i][j]) != m[1].end())
                            return false;
                        m[9].insert({board[i][j],0});
                    }
                }
            }
        }
        return true;
    }
};
