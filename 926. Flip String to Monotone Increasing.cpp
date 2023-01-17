class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        int co = 0;

        for(auto c: s){
            if(c == '1')
                co++;
            else {
                ans++;
                ans = min(co, ans);
            }
        }
        return ans;
    }
};
