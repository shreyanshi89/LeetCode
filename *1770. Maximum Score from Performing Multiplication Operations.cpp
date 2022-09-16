// Brute Force (TLE)
class Solution {
public:
    
    int score(vector<int>& nums,vector<int>& multipliers,int i,int k,int j){
        if(k == multipliers.size())
            return 0;
        
        int start = (multipliers[k] * nums[i]) + score(nums,multipliers,i+1,k+1,j);
        int end = (multipliers[k] * nums[j]) + score(nums,multipliers,i,k+1,j-1);
        return max(start, end);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return score(nums,multipliers,0,0,nums.size()-1);
    }
};

// Optimized (Using DP)
/*
class Solution {
public:
    
    int score(vector<int>& nums,vector<int>& multipliers,int i,int j,int k,vector<vector<int>>& dp){
        if(i == multipliers.size())
            return 0;
        
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        int start = (multipliers[i] * nums[j]) + score(nums,multipliers,i+1,j+1,k,dp);
        int end = (multipliers[i] * nums[k]) + score(nums,multipliers,i+1,j,k-1,dp);
        return dp[i][j] = max(start, end);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return score(nums,multipliers,0,0,n-1,dp);
    }
};  
*/
