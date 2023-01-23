class Solution {
public:

    bool isPalindrome(string& str, int i, int j){
        while(i < j){
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }

    int partition(int i, int j, string& s, vector<int>& dp){
        if(i >= j || isPalindrome(s,i,j))
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                int res = 1 + partition(k+1, j, s, dp);
                ans = min(ans, res);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return partition(0, n-1, s, dp);;
    }
};
