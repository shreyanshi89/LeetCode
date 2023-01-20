class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(auto c: t){
            if(c == s[i])
                i++;
        }
        if(i == s.length())
            return true;
        return false;
    }
};
