// Bit Manipulation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int ctr = 0;
        
        for(int num: data){
            if(ctr == 0){
                if(num >> 5 == 0b110)
                    ctr = 1;
                else if(num >> 4 == 0b1110)
                    ctr = 2;
                else if(num >> 3 == 0b11110)
                    ctr = 3;
                else if(num >> 7 == 0b1)
                    return false;
            }
            else{
                if(num >> 6 != 0b10)
                    return false;
                ctr--;
            }
        }
        return ctr == 0;
    }
};
