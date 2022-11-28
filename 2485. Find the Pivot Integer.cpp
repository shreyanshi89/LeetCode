class Solution {
public:
    int pivotInteger(int n) {
        vector<int> res1(n);
        vector<int> res2(n);
        
        res1[0] = 1;
        for(int i=1;i<n;i++)
            res1[i] = res1[i-1] + i+1;
        
        res2[n-1] = n;
        for(int i=n-2;i>=0;i--)
            res2[i] = res2[i+1] + i+1;
        
        for(int i=0;i<n;i++){
            if(res1[i] == res2[i])
                return i+1;
        }
        return -1;
    }
};
