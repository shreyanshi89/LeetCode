class Solution {
public:
    vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    vector<int> integer = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string intToRoman(int num) {
        string ans;
        
        for(int i = 12;num != 0;i--){
            while(num >= integer[i]){
                num -= integer[i];
                ans += roman[i];
            }
        }
        return ans;
    }
};
