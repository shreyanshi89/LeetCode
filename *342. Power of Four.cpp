class Solution {
public:
    bool isPowerOfFour(int n) {
        int i = 0;
        long long num = LONG_MIN;
        cout<<num;
        while(num < n)
            num = pow(4,i++);
        
        if(num == n)
            return true;
        return false;
    }
};
