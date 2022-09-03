class Solution {
public:
    
    void solution(int n,int k,vector<int>& ans,int num){
        if(n<=0){
            ans.push_back(num);
            return;
        }
        
        for(int i=0;i<10;i++){
            if(num == 0 && i == 0)
                continue;
            else if(i != 0 && num == 0)
                solution(n-1,k,ans,i);
            else if(abs(num%10 - i) == k)
                solution(n-1,k,ans,num*10+i);
                
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        solution(n,k,ans,0);
        return ans;
    }
};
