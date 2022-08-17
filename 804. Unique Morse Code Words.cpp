class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto word:words){
            string res = "";
            for(int i=0;i<word.length();i++){
                res += vec[word[i] - 'a'];
            }
            s.insert(res);
        }
    
        return s.size();
    }
};
