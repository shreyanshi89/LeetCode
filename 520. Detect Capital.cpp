class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i=1;i<word.length();i++){
            if(word[i] < 91 && word[i] > 64 && word[i-1] > 90)
                return false;
            else if(word[i] > 90 && word[i-1] < 91 && word[i-1] > 64 && i-1 > 0)
                return false;
        }
        return true;
    }
};
