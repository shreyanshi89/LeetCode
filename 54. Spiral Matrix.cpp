class Solution {
public:

    void path(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<int>>& matrix, vector<int>& ans, int move){
        ans.push_back(matrix[i][j]);
        vis[i][j] = true;

        if(move == 0 && j + 1 < n && !vis[i][j+1])
            path(i, j+1, m, n, vis, matrix, ans, move);

        move = 1;
        if(move == 1 && i+1 < m && !vis[i+1][j])
            path(i+1, j, m, n, vis, matrix, ans, move);

        move = 2;
        if(move == 2 && j-1 > -1 && !vis[i][j-1])
            path(i, j-1, m, n, vis, matrix, ans, move);

        move = 3;
        if(move == 3 && i-1 > -1 && !vis[i-1][j])
            path(i-1, j, m, n, vis, matrix, ans, move);
        
        move = 0;
        if(move == 0 && j + 1 < n && !vis[i][j+1])
            path(i, j+1, m, n, vis, matrix, ans, move);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        path(0, 0, m, n, vis, matrix, ans, 0);
        return ans;
    }
};
