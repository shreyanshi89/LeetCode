class Solution {
public:

    int ways(int n,int& ans,vector<int>& dp){
        if(n < 4)
            return n;

        else if(dp[n] != -1)
            return dp[n];
        
        else 
            dp[n] = ways(n-1,ans,dp) + ways(n-2,ans,dp);
        return dp[n];
    }

    int climbStairs(int n) {
        int ans = 0;
        vector<int> dp(n+1,-1);
        return ways(n,ans,dp);
    }
};
