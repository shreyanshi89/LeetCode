class Solution {
public:
    string largestPalindromic(string num) {
        string s;
        
        int arr[10] = {0};
        for(int i=0;i<num.length();i++)
            arr[num[i] - '0']++;
        
        int n = -1;
        int j = 9;
        while(j >= 0){
            
            if(arr[j] > 1){
                for(int i=0;i<arr[j]/2;i++) 
                    s.push_back(j + '0');
                    
                if(arr[j] % 2 != 0 && n == -1){     
                        n = j;
                }
            }
            
            else if(arr[j] == 1 && n == -1)
                    n = j;
            
            j--;
        }
        
        if(s[0] == '0')
            s.resize(0);
        
        int size = s.size();
        if(n != -1)
            s.push_back(n + '0');

        while(size)
            s.push_back(s[--size]);
        
        if(s.size() == 0)
            s.push_back('0');
        return s;
    }
};
