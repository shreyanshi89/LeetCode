class Solution {
public:

    int solution(int i, vector<int>& startTime, vector<vector<int>>& job, int n, vector<int>& dp){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ind = lower_bound(startTime.begin(), startTime.end(), job[i][1]) - startTime.begin();

        int pick = job[i][2] + solution(ind, startTime, job, n, dp);
        int notPick = solution(i+1, startTime, job, n, dp);

        return dp[i] =  max(pick, notPick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<vector<int>> job;
        for(int i=0;i<n;i++)
            job.push_back({startTime[i], endTime[i], profit[i]});

        sort(startTime.begin(), startTime.end());
        sort(job.begin(), job.end());

        vector<int> dp(n+1, -1);
        return solution(0, startTime, job, n, dp);
    }
};
