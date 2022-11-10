// Two Pointer Approach
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(auto str: s){
            if(str == '*')
                j--;
            else
                s[j++] = str;
        }
        return s.substr(0,j);
    }
};

/*     OR 
//     Stack Approach
class Solution {
public:
    string removeStars(string s) {
        string ans = "";

        for(auto str: s){
            if(str == '*')
                ans.pop_back();
            else
                ans.push_back(str);
        }
        return ans;
    }
};
*/
