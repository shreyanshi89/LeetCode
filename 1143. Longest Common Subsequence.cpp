class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int res[1001][1001] = {};

        for(int i=0;i<=text1.size();i++){
            for(int j=0;j<=text2.size();j++){
                res[i+1][j+1] = text1[i] == text2[j]? res[i][j] + 1 : max(res[i+1][j], res[i][j+1]);
            }
        }
        return res[text1.size()][text2.size()];
    }
};
