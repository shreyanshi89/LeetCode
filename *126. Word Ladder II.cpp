
class Solution {
public:    
    unordered_map<string, int> level;
    vector<vector<string>> ans;
    vector<string> num;
    
    void dfs(string src, string dest){
        if(src == dest){
            reverse(num.begin(), num.end());
            ans.push_back(num);
            reverse(num.begin(), num.end());
            return;
        }
        
        int curr_level = level[dest]; 
        for(int i=0; i<src.length(); i++){
            string temp = dest;
            for(char j='a'; j<='z'; j++){
                temp[i] = j;
                if(level.find(temp) != level.end() && level[temp] == curr_level-1){  
                    num.push_back(temp);   
                    dfs(src, temp);                                      
                    num.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    
        unordered_map<string, bool>stored;
        for(auto word: wordList)
            stored[word] = true;
        
        if(stored.find(endWord) == stored.end()) 
            return ans;
        
        queue<string> q;                        
        q.push(beginWord);
        level[beginWord] = 0;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                string curr = q.front();                      
                q.pop();
                
                for(int i=0; i<curr.length(); i++){
                    string temp = curr;
                    for(char c='a'; c<='z'; c++){
                        temp[i] = c;                     
                        if(stored.find(temp) != stored.end() && level.find(temp) == level.end()){
                            level[temp] = level[curr] + 1;   
                            q.push(temp);      
                        }
                    }
                }
            }
        }
        
        num.push_back(endWord);
        dfs(beginWord, endWord);
        
        return ans;
    }
};
