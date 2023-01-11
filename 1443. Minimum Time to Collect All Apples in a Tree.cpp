class Solution {
public:
    int dfs(vector<bool>& hasApple,vector<vector<int>>& tree,int node,int d,int prev){
        int result=0,temp;
        for(int &i:tree[node]){
	        if(i != prev){
	        temp = dfs(hasApple,tree,i,d+1,node);
	        if(temp)
                result += temp-d;
	        }
        }
        return result || hasApple[node]? result+d:0;    
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);

        for(vector<int> &e:edges)
            tree[e[0]].push_back(e[1]),tree[e[1]].push_back(e[0]);

        return dfs(hasApple,tree,0,0,-1)*2;
    }
};
