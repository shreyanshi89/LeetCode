class Solution {
public:

    void dfs(int i, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> res){
        if(i == graph.size() - 1){
            res.push_back(graph.size() - 1);
            ans.push_back(res);
            return;
        }
        res.push_back(i);
        for(auto n: graph[i])            
            dfs(n, graph, ans, res);
        
    } 

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        dfs(0, graph, ans, {});
        return ans;
    }
};
