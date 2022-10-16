class Solution {
public:

    int solution(vector<int>& jobDifficulty,int i, int d, int n, vector<vector<int>>& dp) {
        if(d == 1)
            return *max_element(jobDifficulty.begin()+i, jobDifficulty.end());
        
        if(dp[i][d] != -1)
            return dp[i][d];

        int res = INT_MAX;
        int m = INT_MIN;
        for(int j=i;j<n - d + 1;j++){
            m = max(m,jobDifficulty[j]);
            res = min(res, m + solution(jobDifficulty, j+1,d-1, n, dp));
        }
        dp[i][d] = res;
        return dp[i][d];
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1, vector<int> (d+1, -1));
        if(n < d)
            return -1;
        return solution(jobDifficulty,0,d,n,dp);
    }
};
