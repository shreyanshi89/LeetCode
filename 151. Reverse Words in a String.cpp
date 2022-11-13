class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        int i = s.length();
        s += ' ';
        while(i >= 0){
            while(i >= 0 && s[i] == ' ')
                i--;
            
            if(i < 0)
                break;

            int j = i;
            while(i >= 0 && s[i] != ' ')
                i--;
            
            if(str.empty())
                str += s.substr(i+1,j-i);
            else 
                str += ' ' + s.substr(i+1,j-i);
        }
        return str;
    }
};
