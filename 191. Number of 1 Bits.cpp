// Using built in function '__builtin_popcount()'

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

//   OR - Using normal looping 
/*
  class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n > 0){
            if(n % 2 == 1)
                ans++;
            n /= 2;
        }
        return ans;
    }
};
*/

//   OR - Bit Manipulation 
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n > 0){
            if(n & 1 > 0)
                ans++;
            n >>= 1;
        }
        return ans;
    }
};
*/
