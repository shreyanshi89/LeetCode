class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int a = 0, size = tokens.size() - 1;
        int res = 0, score = 0;
        
        while(a <= size){
            if(power >= tokens[a]){
                power -= tokens[a++];
                score++;
                res = max(res,score);
            }
            else if(score >= 1){
                score--;
                power += tokens[size--];
            }
            else 
                break;
        }
        return res;
    }
};
