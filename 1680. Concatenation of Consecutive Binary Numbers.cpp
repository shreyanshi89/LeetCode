class Solution {
public:
    #define MOD 1000000007
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i=1;i<=n;i++){
            int a = i;
            int ctr = 0;
            while(a > 0){
                a /= 2;
                ctr++;
            }
            ans = ((ans << ctr) + i) % MOD;
        }
        return ans % MOD;
    }
};
