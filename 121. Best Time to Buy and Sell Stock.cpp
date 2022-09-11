class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = prices[0];
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] > min){
                int res = prices[i] - min;
                ans = max(ans, res);
            }
            
            else 
                min = prices[i];
        }
        return ans;
    }
};
