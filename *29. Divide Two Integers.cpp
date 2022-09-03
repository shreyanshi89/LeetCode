// Bit Manipulation

class Solution {
public:
    int divide(int dividend, int divisor) {
        long ans = 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1:1;
        long divd = abs(dividend);
        long divs = abs(divisor);
        
        while(divd >= divs){
            long temp = divs;
            int a = 1;
            while(temp << 1 <= divd){
                temp = temp << 1;
                a = a << 1;
            }
            divd -= temp;
            ans += a;
        }
        return sign * ans;
    }
};
