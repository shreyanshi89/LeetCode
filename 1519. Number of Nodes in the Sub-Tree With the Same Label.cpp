class Solution {
public:
    void solution(vector<vector<int>>& tree, int curr, int parent, vector<int>& ans, string& labels, vector<int>& count){
        char l = labels[curr];

        int ctr = count[l - 'a'];
        count[l - 'a']++;

        for(auto num: tree[curr]){
            if(num == parent)
                continue;
            else 
                solution(tree, num, curr, ans, labels, count);
        }
        int ctr2 = count[l - 'a'];
        ans[curr] = ctr2 - ctr;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n,0);
        vector<vector<int>> tree(n);

        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> count(26,0);
        solution(tree, 0, -1, ans, labels, count);
        
        return ans;
    }
};
