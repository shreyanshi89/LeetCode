class Solution {
public:

    void parenthesis(int n, vector<string>& ans, int o, int c, string str){
        if(o == n && c == n){
            ans.push_back(str);
            return;
        }

        if(o <= n)
            parenthesis(n, ans, o+1, c, str+'(');

        if(c < o)
            parenthesis(n, ans, o, c+1, str+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        parenthesis(n, ans, 0, 0, "");
        return ans;
    }
};
