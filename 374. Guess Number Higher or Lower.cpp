/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int mid;
        int left = 0;
        int right = n;

        while(1){
            mid = left + (right - left)/2;
            int x = guess(mid);
            if(x == 1)
                left = mid + 1;
            else if(x == -1)
                right = mid - 1;
            else 
                break;
        }
        return mid;
    }
};
