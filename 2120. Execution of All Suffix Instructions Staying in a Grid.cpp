class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>ans;

        for(int i=0;i<s.length();i++){
            int res = 0;
            int x = startPos[0];
            int y = startPos[1];
            for(int j=i;j<s.length();j++){
                if(s[j] == 'U' && x-1 >= 0){
                    res++;
                    x -= 1;
                }
                else if(s[j] == 'D' && x+1 < n){
                    res++;
                    x += 1;
                }
                else if(s[j] == 'L' && y-1 >= 0){
                    res++;
                    y -= 1;
                }
                else if(s[j] == 'R' && y+1 < n){
                    res++;
                    y += 1;
                }
                else 
                    break;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
