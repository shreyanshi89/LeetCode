class Solution {
public:

    bool vowel(char c){
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        string str = "";
        int n = s.length();
        for(int i=0;i<n;i++){
            if(vowel(s[i]))
                str += s[i];
        }

        int ind = 0;
        for(int i=n-1;i>=0;i--){
            if(vowel(s[i]))
                s[i] = str[ind++];
        }
        return s;
    }
};
