class Solution {
public:

    void dfs1(vector<unordered_set<int>>& tree, vector<int>& ans, vector<int>& ctr, int root, int prev){
        for(auto i: tree[root]){
            if(i == prev)
                continue;
            dfs1(tree, ans, ctr, i, root);
            ctr[root] += ctr[i];
            ans[root] += ans[i] + ctr[i];
        }
    }

    void dfs2(vector<unordered_set<int>>& tree, vector<int>& ans, vector<int>& ctr, int root, int prev){
        for(auto i: tree[root]){
            if(i == prev)
                continue;
            ans[i] = ans[root] - ctr[i] + ctr.size() - ctr[i];                
            dfs2(tree, ans, ctr, i, root);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(n);
        vector<int> ans(n, 0);
        vector<int> ctr(n, 1);

        for(auto num: edges){
            tree[num[0]].insert(num[1]);
            tree[num[1]].insert(num[0]);
        }

        dfs1(tree, ans, ctr, 0, -1);
        dfs2(tree, ans, ctr, 0, -1);
        return ans;
    }
};
