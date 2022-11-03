class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> m;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;

        bool b = false;
        for(auto num: m){
            string str = num.first;
            reverse(str.begin(), str.end());
            auto it = m.find(str);
            if(it != m.end() && str != num.first){
                int min = num.second < it->second ? num.second : it->second;
                ans += (min * 2);
            }
            else if (str == num.first) {
                if(!b && num.second % 2 != 0) {
                    ans += (num.second * 2);    
                    b = true;
                }
                else 
                    ans += (num.second / 2 * 4);
            }
        }
        return ans;
    }
};
