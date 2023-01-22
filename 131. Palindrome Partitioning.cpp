class Solution {
public:

    bool isPalindrome(string str){
        int i = 0;
        int j = str.length() - 1;
        while(i <= j){
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }

    void solve(int ind, string s, vector<string> res, vector<vector<string>>& ans){
        if(ind >= s.length()){
            ans.push_back(res);
            return;
        }

        for(int i=1;i<=s.length();i++){
            if(ind + i <= s.length() && isPalindrome(s.substr(ind, i))){
                res.push_back(s.substr(ind, i));
                solve(ind+i, s, res, ans); 
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        solve(0, s, {}, ans);
        return ans;
    }
};
