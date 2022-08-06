class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int numTest = (minutesToTest / minutesToDie) + 1;
        int pigs = ceil(log(buckets)/log(numTest)); 
        return pigs;
    }
};
