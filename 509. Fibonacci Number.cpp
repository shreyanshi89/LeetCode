// DP
class Solution {
public:
    int solution(int n,vector<int>& dp){
        if(n < 2)
            return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = solution(n-1, dp) + solution(n-2, dp);
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solution(n, dp);
    }
};

/*
//  OR (Recursion)
class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        return fib(n-1) + fib(n-2);
    }
};

//  OR (Looping)
class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        
        int bprev = 0;
        int prev = 1;

        for(int i=2;i<=n;i++){
            int curr = bprev + prev;
            bprev = prev;
            prev = curr;
        }
        return prev;
    }
};
*/
