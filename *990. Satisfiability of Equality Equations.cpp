class Solution {
public:
    int num[26];
    int find(int x){
        return num[x] == x? x: (num[x] = find(num[x]));
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)  num[i] = i;

        for(auto n:equations){
            if(n[1] == '=')
                num[find(n[0] - 'a')] = find(n[3] - 'a');
        }
        
        for(auto n: equations){
            if(n[1] == '!' && find(n[0] - 'a') == find(n[3] - 'a'))
                return false;
        }
        return true;
    }
};
