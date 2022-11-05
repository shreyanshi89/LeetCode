class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
        int n = s.length();
        while(start<n){
            if(start + k >= n)
                reverse(s.begin() + start, s.end());
            else
                reverse(s.begin() + start, s.begin() + start + k);
            start += 2*k;
        }
        return s;
    }
};
