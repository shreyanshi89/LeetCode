class Solution {
public:

    int solution(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = max(solution(i+1, nums, dp), nums[i] + solution(i+2, nums, dp));
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solution(0, nums, dp);
    }
};
