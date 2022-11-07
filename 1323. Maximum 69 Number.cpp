class Solution {
public:

    void digit(int num, vector<int>& res){
        while(num) {
            res.push_back(num % 10);
            num /= 10;
        }
    }

    int maximum69Number (int num) {
        vector<int> res;
        digit(num, res);

        for(int i=res.size() - 1;i>=0;i--){
            if(res[i] == 6){
                res[i] = 9;
                break;
            }
        }

        int ans = 0;
        for(int i=res.size()-1;i>=0;i--)
            ans = ans*10 + res[i];
        
        return ans;

    }
};
