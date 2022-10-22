class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() == 0 || s.length() < t.length())
            return "";
        
        unordered_map<char, int> m;
        for(int i=0;i<t.length();i++)
            m[t[i]]++;

        int mctr = 0;
        int start = 0;
        int min = INT_MAX;
        int left = 0;

        for(int i=0;i<s.length();i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]]--;
                if(m[s[i]] >= 0)
                    mctr++;
                cout<<mctr<<" ";
            }

            while(mctr == t.length()){
                if(i - start + 1 < min){
                    min = i - start + 1; 
                    left = start;
                }
                if(m.find(s[start]) != m.end()){
                    m[s[start]]++;
                    if(m[s[start]] > 0)
                        mctr--;
                }    
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};
