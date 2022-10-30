class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<vector<int>> q;
		
        q.push({0,0,0,k});
        while(!q.empty()){
            auto curr = q.front();
            int x = curr[0];
            int y = curr[1];
            q.pop();
			
            if(x < 0 || y < 0 || x >= m || y >= n){
                continue;
            }
			
            if(x == m - 1 && y== n - 1)
                return curr[2];

            if(grid[x][y] == 1){
                if(curr[3] > 0) 
                    curr[3]--;
                else
                    continue;
            }
			
            if(vis[x][y] != -1 && vis[x][y] >= curr[3])
                continue;
            vis[x][y] = curr[3];
            
            q.push({x,y-1,curr[2]+1,curr[3]});
            q.push({x+1,y,curr[2]+1,curr[3]});
            q.push({x,y+1,curr[2]+1,curr[3]});
            q.push({x-1,y,curr[2]+1,curr[3]});
            
        }
        return -1;
    }
};
