class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int a = 28;
        int q = n / 7;

        for(int i=0;i<q;i++){
            sum += a;
            a += 7;
        }

        int r = n % 7;
        a = (r*(2*(q+1) + (r-1)))/2;
        return sum + a;
    }
};
