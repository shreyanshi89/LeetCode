// Using inbuilt function :- __builtin_popcount()
// __builtin_popcount (x) is a function in C++ returns the number of 1-bits set in an int x. In fact, "popcount" stands for "population count

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};

/*
// Iterative approach
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ctr = 0;
        while(start > 0 || goal > 0){
            int a = start % 2;
            int b = goal % 2;
            if(a != b)
                ctr++;
            start /= 2;
            goal /= 2;
        }
        return ctr;
    }
};
*/
