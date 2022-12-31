class Solution {
public:

    void path(int i, int j, vector<vector<int>>& grid, int& ctr, int res, int& ans){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return;

        if(grid[i][j] == 2){
            if(res == ctr)
                ans++;
            return;
        }

        grid[i][j] = -1;
        path(i+1, j, grid, ctr, res+1, ans);
        path(i-1, j, grid, ctr, res+1, ans);
        path(i, j+1, grid, ctr, res+1, ans);
        path(i, j-1, grid, ctr, res+1, ans);
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int x;
        int y;
        int ctr = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                else if(grid[i][j] == 0)
                    ctr++;
            }
        }
        int ans = 0;
        path(x, y, grid, ctr, -1, ans);
        return ans;
    }
};
