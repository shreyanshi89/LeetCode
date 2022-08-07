class Solution {
public:
    #define MOD 1000000007
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n,vector<int>(5,0));
        
        for(int i=0;i<5;i++)
            dp[n-1][i] = 1;
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<5;j++){
                if(j == 0)
                    dp[i][j] = dp[i+1][j+1];
                else if(j == 1)
                    dp[i][j] = (dp[i+1][j-1] + dp[i+1][j+1])%MOD;
                else if(j == 2){
                    dp[i][j] = (dp[i][j] + dp[i+1][j-2])%MOD;
                    dp[i][j] = (dp[i][j] + dp[i+1][j-1])%MOD;
                    dp[i][j] = (dp[i][j] + dp[i+1][j+1])%MOD;
                    dp[i][j] = (dp[i][j] + dp[i+1][j+2])%MOD;
                }
                else if(j == 3)
                    dp[i][j] = (dp[i+1][j-1] + dp[i+1][j+1])%MOD;
                else 
                    dp[i][j] = dp[i+1][j-4];
            }
        }
        int res = 0;
        for(int i=0;i<5;i++)
            res = (res+dp[0][i])%MOD;
        return res;
    }
};
