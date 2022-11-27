class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        vector<unordered_map<int, int>> dp(nums.size()+1);

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long diff = (long long)nums[i] - (long long)nums[j];
                
                if(diff < INT_MIN || diff>= INT_MAX)
                    continue;

                int endj = dp[j][(int)diff];
                int endi = dp[i][(int)diff];

                ans += endj;
                dp[i][diff] = endi + endj + 1;
            }
        }
        return ans;
    }
};
