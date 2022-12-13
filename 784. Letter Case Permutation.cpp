class Solution {
public:

    void solution(int i, string str, string s, vector<string>& ans){
        if(str.length() == s.length()){
            ans.push_back(str);
            return;
        }

        solution(i+1, str+s[i], s, ans);
        if(s[i] >= 65 && s[i] <= 90)
            solution(i+1, str+(char)(s[i] + 32), s, ans);
        else if(s[i] >= 97 && s[i] <= 122)
            solution(i+1, str+(char)(s[i] - 32), s, ans);
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solution(0, "", s, ans);
        return ans;
    }
};
