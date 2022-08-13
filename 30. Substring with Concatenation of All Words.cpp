class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> m;
        for(auto word:words)
            m[word]++;
        
        int n = s.size();
        int num = words.size();
        int len = words[0].size();
            
        for(int i=0;i<n-num*len+1;i++){
            unordered_map<string, int> mc;
            int j = 0;
            for(j=0;j<num;j++){
                string word = s.substr(i+j*len,len);
                
                if(m.find(word) != m.end()){
                    mc[word]++;
                if(m[word] < mc[word])
                    break;
                }
                else 
                    break;
            }
            if(j == num)
                ans.push_back(i);
        }
        return ans;
    }
};
