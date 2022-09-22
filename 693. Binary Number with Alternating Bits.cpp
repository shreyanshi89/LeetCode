class Solution {
public:
    
    void binary(int n,vector<int>& res){
        while(n > 0){
            res.push_back(n % 2);
            n /= 2;
        }
    }
    
    bool hasAlternatingBits(int n) {
        vector<int> res;
        binary(n,res);
        reverse(res.begin(),res.end());
        for(int i=1;i<res.size();i++){
            if(res[i] == res[i-1])
                return false;
        }
        return true;
    }
};

// OR
/*
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr = n % 2;
        n /= 2;
        while(n > 0){
            if(curr == n % 2)
                return false;
            curr = n % 2;
            n /= 2;
        }
        return true;
    }
};
*/
