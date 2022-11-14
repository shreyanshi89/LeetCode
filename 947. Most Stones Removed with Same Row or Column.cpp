class Solution {
public:
    void dfs(vector<vector<int>>& stones,vector<bool>& vis,int ind){
        vis[ind] = true;
        for(int i=0;i<stones.size();i++) {
            if(!vis[i] and (stones[ind][0] == stones[i][0] || stones[ind][1] == stones[i][1]))
                dfs(stones,vis,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<bool>vis(stones.size(),false);
        int cnt = stones.size();

        for(int i=0;i<stones.size();i++){
            if(vis[i]) 
                continue;
            cnt--;               
            dfs(stones,vis,i);
        }
        return cnt;
    }
};
