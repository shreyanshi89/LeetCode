//  O(n^2)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int ans = 0;

        for(int i=0;i<n-m+1;i++){
            int a = i;
            for(int j=0;j<m;j++){ 
                if(needle[j] == haystack[a]){
                    ans = i;
                    a++;
                }

                else if(needle[j] != haystack[a]){
                    ans = -1;
                    break;
                }
            }
            if(ans != -1)
                return i;
        }
        return -1;
    }
};
