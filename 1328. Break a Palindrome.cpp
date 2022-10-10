class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n == 1)
            return "";
    
        for(int i=0;i<n;i++){
            if(n % 2 != 0 && i == n/2)
                continue;
            else if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] += 1;
        return palindrome;
    }
};
