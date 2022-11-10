class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        int j = 0;
        for(auto str: s){
            if(i > 0 && str == '#')
                i--;
            else if(str != '#')
                s[i++] = str;
        }
        for(auto str: t){
            if(j > 0 && str == '#')
                j--;
            else if(str != '#')
                t[j++] = str;
        }
        return s.substr(0,i) == t.substr(0,j);
    }
};
