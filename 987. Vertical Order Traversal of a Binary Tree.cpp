class Solution {
public:
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int,map<int, multiset<int>>> m;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int v = p.second.first;
            int l = p.second.second;
            m[v][l].insert(node->val);
            if(node->left)
                q.push({node->left,{v-1,l+1}});
            if(node->right)
                q.push({node->right,{v+1,l+1}});
        }
        
        for(auto num:m){
            vector<int> col;
            for(auto n:num.second){
                col.insert(col.end(),n.second.begin(),n.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
