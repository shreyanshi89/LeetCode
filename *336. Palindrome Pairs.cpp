class Solution {
public:
    
    bool palindrome(string num){
        string rev = num;
        reverse(rev.begin(),rev.end());
        return rev == num;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> m;
        
        for(int i=0;i<words.size();i++)
            m[words[i]] = i;
        
        for(int i=0;i<words.size();i++){
            string word = words[i];
            string w = words[i];
            reverse(w.begin(),w.end());
            if(m.find(w) != m.end() && m[w] != i)
                ans.push_back({i,m[w]});
            
            if(palindrome(word) && m.find("") != m.end() && m[""] != i){
                ans.push_back({i,m[""]});
                ans.push_back({m[""],i});
            }
            
            
            int n = word.length() - 1;
            int l = n;
            string str = "";
            while(l >= 1){
                str += word[l];
                if(m.find(str) != m.end() && palindrome(word.substr(0,l)) &&  m[str] != i)
                    ans.push_back({m[str],i});
                l--;
            }
            
            int s = 0;
            str = "";
            string temp;
            while(s < n){
                str += word[s];
                temp = str;
                reverse(temp.begin(),temp.end());
                if(m.find(temp) != m.end() && palindrome(word.substr(s+1,l-1-s)) &&  m[temp] != i)
                    ans.push_back({i,m[temp]});
                s++;
            }
        }
        
        return ans;
    }
};
