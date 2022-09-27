class Solution {
public:
    string pushDominoes(string dominoes) {
        string res = "";
        int n = dominoes.size();
        vector<int> lt(n,0);
        vector<int> rt(n,0);
        int a = 0;
        char prev = dominoes[0];
        
        for(int i=0;i<n;i++){
            if(dominoes[i] == '.' && prev == 'R')
                rt[i] = ++a;
            else if(dominoes[i] == 'R'){
                prev = 'R';
                a = 0;
            }
            else if(dominoes[i] == 'L'){
                a = 0;
                prev = 'L';
            }
        }
        a = 0;
        prev = dominoes[n-1];
        
        for(int i=n-1;i>-1;i--){
            if(dominoes[i] == '.' && prev == 'L')
                lt[i] = ++a;
            else if(dominoes[i] == 'L'){
                prev = 'L';
                a = 0;
            }
            else if(dominoes[i] == 'R'){
                a = 0;
                prev = 'R';
            }
        }
        
        for(int i=0;i<n;i++){
            if(lt[i] == 0 && rt[i] == 0)
                res += dominoes[i];
            else if(lt[i] == 0)
                res += 'R';
            else if(rt[i] == 0)
                res += 'L';
            else if(lt[i] < rt[i])
                res += 'L';
            else if(rt[i] < lt[i])
                res += 'R';
            else if(rt[i] == lt[i])
                res += '.';
        }
        return res;
    }
};
