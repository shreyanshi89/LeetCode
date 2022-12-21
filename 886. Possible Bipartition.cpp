class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1, 0);
        vector<vector<int>> adj(n+1);

        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i=1;i<n+1;i++){
            if(color[i] == 0){
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(auto node: adj[curr]){
                        if(color[node] == color[curr])
                            return false;

                        if(color[node] == 0){
                            q.push(node);
                            color[node] = -1*color[curr];
                        }
                    }
                }
            }
        }
        return true;
    }
};
