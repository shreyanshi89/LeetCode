class Solution {
public:
    
    bool canReplace(char s[],int len,int pos,char t[]){
        for(int i=0;i<len;i++){
            if(t[i+pos] != '*' && t[i+pos] != s[i])
                return false;
        }            
        return true;
    }
    
    int replace(int pos,char t[],int len,int ctr){
        for(int i=0;i<len;i++){
            if(t[i+pos] != '*'){
                t[i+pos] = '*';
                ctr++;
            }
        }
        return ctr;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> v;t
        char s[stamp.length()+1];
        strcpy(s,stamp.c_str());
        char t[target.length()+1];
        strcpy(t,target.c_str());
        
        int ctr = 0;
        vector<bool> visited(target.length(),false);
        
        while(ctr != target.length()){
            bool didChange = false;
            for(int i=0;i<=target.length() - stamp.length();i++){
                if(!visited[i] && canReplace(s,stamp.length(),i,t)){
                    ctr = replace(i,t,stamp.length(),ctr);
                    v.push_back(i);
                    visited[i] = true;
                    didChange = true;
                   
                    if(ctr == target.length()){
                        break;
                    }
               } 
            }
            if(!didChange)
                return {};
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
