class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        int n = chars.size();
        int a = 1;
        for(int i=0;i<n;i++){
            if(a == 1)
                s.push_back(chars[i]);
            
            if(i == n-1 && a > 1){
                string str = to_string(a);
                    for(auto ch: str)
                        s.push_back(ch);
            }
                
            
            else if(i < n-1 && chars[i] != chars[i+1]){
                if(a != 1){
                    string str = to_string(a);
                    for(auto ch: str)
                        s.push_back(ch);
                }
                a = 1;
            }

            else 
                a++;
        }
        chars = s;
        return s.size();
    }
};
