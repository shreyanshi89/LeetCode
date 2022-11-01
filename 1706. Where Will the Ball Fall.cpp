class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);

        for(int a=0;a<n;a++){
            int i = 0;
            int j = a;
            while(i != m){
                if(grid[i][j] == 1){
                    if(j == n-1 || grid[i][j+1] == -1){
                        ans[a] = -1;
                        break;
                    }
                    else {
                        i += 1;
                        j += 1;
                    }
                }
                else if(grid[i][j] == -1){
                    if(j == 0 || grid[i][j-1] == 1){
                        ans[a] = -1;
                        break;
                    }
                    else{
                        i += 1;
                        j -= 1;
                    }
                }
                ans[a] = j;
            }
        }
        return ans;
    }
};
