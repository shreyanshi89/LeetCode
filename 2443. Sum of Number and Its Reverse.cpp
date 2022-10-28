class Solution {
public:
    
    int reverse(int n){
        int revs = 0;
        while(n){
            int rem = n % 10;
            revs = revs * 10 + rem;
            n /= 10;
        }
        return revs;
    }
    
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            int revs = reverse(i);
            if(i + revs == num)
                return true;
        }
        return false;
    }
};

/*
OR
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int revs = stoi(s);
            if(i + revs == num)
                return true;
        }
        return false;
    }
};
*/
