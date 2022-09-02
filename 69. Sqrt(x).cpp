// Brute Force 
class Solution {
public:
    int mySqrt(int x) {
        long long sqrt = 1;
        while(true){
            if(sqrt * sqrt <= x){
                sqrt++;
            }
            else break;
        }
        return sqrt-1;
    }
};

/*
T.C :- O(logn)
class Solution {
public:
    
    int mySqrt(int x) {
        int mid;
        int l = 1;
        int h = x;
        while(l<=h){
            mid = l + (h - l)/2;
            if(mid > x / mid)
                h = mid-1;
            else{
                l = mid+1;
                if(mid + 1 > x/(mid + 1))
                    return mid;
            }
        }
        return mid;
    }
};
*/
