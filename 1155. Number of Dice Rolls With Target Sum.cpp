class Solution {
public:
    #define MOD 1000000007

    int dice(int n,int k,int target, vector<vector<int>>& dp){
        if(target < 0)
            return 0;
        if(target == 0 && n != 0)
            return 0;
        if(n == 0 && target != 0)
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(dp[n][target] != -1)
            return dp[n][target];
        long long ans = 0;
        for(int i=1;i<=k;i++)
            ans += dice(n-1, k, target - i ,dp);
        
        return dp[n][target] = ans % MOD;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        int ans = dice(n,k,target,dp);
        return ans % MOD;
    }
};
