class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool present = false;
        
        for(auto word: wordList){
            if(word == endWord)
                present = true;
            s.insert(word);
        }
        
        if(present == false)
            return 0;
        
        int length = 0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            length++;
            int qsize = q.size();
            while(qsize--){
                string curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(char ch = 'a' ; ch<='z';ch++){
                        temp[i] = ch;
                        if(curr.compare(temp) == 0)
                            continue;
                        if(temp.compare(endWord) == 0)
                            return length+1;
                        if(s.find(temp) != s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
