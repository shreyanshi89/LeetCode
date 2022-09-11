class Solution {
public:
    
    int func(int ind, int buy, vector<int> prices, int n, int k, vector<vector<vector<int>>>& dp){
        
        if(k == 0 || ind == n)
            return 0;
    
        if(dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        
        if(buy){
            return dp[ind][buy][k] = max((-prices[ind] + func(ind+1,0,prices,n,k,dp)), 0 + func(ind+1,1,prices,n,k,dp));
        }
        
        else{
            return dp[ind][buy][k] = max((prices[ind] + func(ind+1,1,prices,n,k-1,dp)), 0 + func(ind+1,0,prices,n,k,dp));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2,vector<int> (k+1,-1)));
        return func(0,1,prices,prices.size(),k,dp);
    }
};
