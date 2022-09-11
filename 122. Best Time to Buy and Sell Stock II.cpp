class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = prices[0];
        for(int i=0;i<prices.size();i++){
            if(min < prices[i]){
                ans += (prices[i] - min);
                min = prices[i];
            }
            
            else
                min = prices[i];
        }
        return ans;
    }
};
