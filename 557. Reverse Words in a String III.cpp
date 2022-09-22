class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        while(i < s.length() && j < s.length()){
            if(s[j+1] == ' ' || j+1 == s.length()){
                reverse(s.begin() + i,s.begin() + j+1);
                j++;
                i = j+1;
            }
            j++;
        }
        return s;
    }
};
