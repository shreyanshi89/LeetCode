class Solution {
public:

    int solution(int i, vector<vector<int>>& tree, string& s, int& ans){
        int a = 0;
        int b = 0;

        for(auto num: tree[i]){
            int curr = solution(num, tree, s, ans);
            if(s[i] == s[num])
                continue;
            if(curr > a)   
                a = curr;
            if(a > b)
                swap(a, b);
        }
        ans = max(ans, a+b+1);
        return b + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int ans = INT_MIN;
        vector<vector<int>> tree(parent.size());

        for(int i=1;i<parent.size();i++)
            tree[parent[i]].push_back(i);
        
        solution(0,tree, s, ans);
        return ans;
    }
};
