class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int col = mat[0].size();
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                 m[i-j].push(mat[i][j]);
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                mat[i][j] = m[i-j].top();
                m[i-j].pop();
            }
        }
        return mat;
    }
};
