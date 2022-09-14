/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int check(unordered_map<int,int>& m,int& ctr){
        int c = 0;
        for(auto num: m){
            if(num.second % 2 != 0)
                c++;
        }
        if(c > 1)
            return 0;
        return 1;
    }
    
    void traverse(TreeNode* root,int& ctr,unordered_map<int,int>& m){
        
        if(!root)
            return;
        m[root->val]++;
        
        if(!root->left && !root->right){
            ctr += check(m,ctr);
        }
        
        traverse(root->left,ctr,m);
        traverse(root->right,ctr,m);
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ctr = 0;
        unordered_map<int,int>m;
        traverse(root,ctr,m);
        return ctr;    
    }
};
