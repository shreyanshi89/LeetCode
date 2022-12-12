class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = -1;
        for(auto num: strs){
            int n=0;
            bool b = false;
            for(int i=0;i<num.length();i++){
                if(num[i] >= 'a' && num[i] <= 'z'){
                    int len = num.length();
                    b = true;
                    ans = max(ans, len);
                    break;
                }
                else 
                    n = n*10 + (num[i] - '0');
            }
            if(!b)
                ans = max(ans, n);
        }
        return ans;
    }
};
