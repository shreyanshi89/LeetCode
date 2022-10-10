class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = INT_MIN;
        int size = logs.size();
        int res[size];
        res[0] = logs[0][1];
        
        for(int i=1;i<size;i++)
            res[i] = logs[i][1] - logs[i-1][1];
        
        int loc = 0;
        for(int i=0;i<size;i++){
            if(res[i] > ans){
                ans = res[i];
                loc = i;
            }
            else if(res[i] == ans){
                loc = logs[i][0]<logs[loc][0]? i:loc;
            }
        }
        return logs[loc][0];
    }
};
