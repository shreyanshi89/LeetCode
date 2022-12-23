class Solution {
public:

    int stock(int i, vector<int>& prices, int buy, vector<vector<int>>& dp){
        if(i >= prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy)
            return dp[i][buy] = max(-prices[i] + stock(i+1, prices, 0, dp), 0 + stock(i+1, prices, 1, dp));
        
        return dp[i][buy] = max(prices[i] + stock(i+2, prices, 1, dp), 0 + stock(i+1, prices, 0, dp));
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return stock(0, prices, 1, dp);
    }
};
