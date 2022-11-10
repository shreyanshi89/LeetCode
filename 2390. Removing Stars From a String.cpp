class Solution {
public:
    string removeStars(string s) {
        string ans = "";

        for(auto str: s){
            if(str == '*')
                ans.pop_back();
            else
                ans.push_back(str);
        }
        return ans;
    }
};
