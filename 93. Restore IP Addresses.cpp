class Solution {
public:

    bool isValid(string str){
        if(str[0] == '0')
            return false;
        int num = stoi(str);
        cout<<num<<" ";
        return num <= 255;
    }

    void ip(int i, string& s, string res, int par, vector<string>& ans){
        if(i >= s.length()){
            if(par == 4){
                res.pop_back();
                ans.push_back(res);
            }
            return;
        }
        
        ip(i+1, s, res + s[i] + '.', par+1, ans);

        if(i+2 <= s.length() && isValid(s.substr(i, 2)))
            ip(i+2, s, res + s.substr(i, 2) + '.', par+1, ans);

        if(i+3 <= s.length() && isValid(s.substr(i, 3)))
            ip(i+3, s, res + s.substr(i, 3) + '.', par+1, ans);
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.length() < 4 || s.length() > 12)
            return {};
        
        vector<string> ans;
        ip(0, s, "", 0, ans);
        return ans;
    }
};
