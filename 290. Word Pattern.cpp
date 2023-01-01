class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        s += ' ';
        for(int i=0;i<pattern.length();i++)
            m[pattern[i]] = "-";

        string str = "";
        int j = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                if(m[pattern[j]] != str && m[pattern[j]] != "-")
                    return false;
                
                m[pattern[j++]] = str;
                str = "";
            }
            else
                str += s[i];
        }

        set<string> st;
        for(auto num: m){
            if(num.second != "-")
                st.insert(num.second);
        }

        if(st.size() != m.size())
            return false;
            
        return true;
    }
};
