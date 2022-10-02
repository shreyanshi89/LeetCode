class Solution {
public:

    int decode(string s, int i, vector<int>& dp){
        if(s[i] == '0')
            return 0;
        if(i == s.length())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        int a = decode(s,i+1,dp);
        int b = 0;
        if((i < s.length() - 1) && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
            b += decode(s,i+2,dp);
        return dp[i] = a+b;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return decode(s, 0, dp);
    }
};
