// Using Unordered Map (Approach 1) : My Approach

class Solution {
public:
    
    int digit(int num){
        int len = 0;
        while(num){
            len++;
            num /= 10;
        }
        return len;
    }
    
    bool compare(unordered_map<int, int> m,int num){
        while(num){
            int r = num % 10;
            auto it = m.find(r);
            if(it == m.end() || it->second == 0)
                return false;
            else 
                it->second = it->second - 1;
            num /= 10;
        }
        return true;
    }
    
    bool reorderedPowerOf2(int n) {
        int a = n;
        int len = 0;
        unordered_map<int, int> m;
        
        while(a){
            len++;
            m[a % 10]++;
            a /= 10;
        }
        int num;
        int i = 0;
        while(true){
            bool b = false;
            num = pow(2,i++);
            if(digit(num) == len){
                b = compare(m,num);
                if(b)
                    return true;
            }
            else if(digit(num) > len)
                break;
        }
        return false;
    }
};

// OR 
// Approach 2 (Bit Manipualation)

/*
class Solution {
public:
    
    string sorted(int num){
        string res = to_string(num);
        sort(res.begin(),res.end());
        return res;
    }
    
    bool reorderedPowerOf2(int n) {
        string str = sorted(n);
        for(int i =0;i<32;i++){
            if(str == sorted(1 << i))
                return true;
        }
        return false;
    }
};
*/
