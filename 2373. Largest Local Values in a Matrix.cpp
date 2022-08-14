class Solution {
public:
    
    int maximum(vector<vector<int>>& grid,int a,int b){
        int max = INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i+a][j+b] > max){
                    max = grid[i+a][j+b];   
                }
            }
        }
        return max;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j] = maximum(grid,i,j);
            }
        }
        return ans;
    }
}; 
