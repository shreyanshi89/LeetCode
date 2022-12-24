class Solution {
public:
#define MOD 1000000007

    int numTilings(int n) {
        vector<long long> res(1001, 0);
        res[1] = 1;
        res[2] = 2;
        res[3] = 5;

        if(n <= 3)
            return res[n];
            
        for(int i=4;i<=n;i++){
            res[i] = 2*res[i-1] + res[i-3];
            res[i] %= MOD;
        }
        return res[n];
    }
};
