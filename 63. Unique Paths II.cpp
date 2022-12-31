// DP Hash Table
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0 ));
        dp[0][1] = 1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

//  Recursive DP
/*
class Solution {
public:

    int paths(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i == obstacleGrid.size() || j == obstacleGrid[0].size() || obstacleGrid[i][j])
            return 0;
            
        if(i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] =  paths(i+1, j, obstacleGrid, dp) + paths(i, j+1, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), -1));
        return paths(0, 0, obstacleGrid, dp);
    }
};
*/
