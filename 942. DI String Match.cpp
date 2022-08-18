class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> num(s.length()+1);
        int a = 0;
        int b = s.length();
        for(int i=0;i<s.length();i++){
            if(s[i] == 'I')
                num[i] = a++;
            else
                num[i] = b--;
        }
        num[s.length()] = b;
        return num;
    }
};
