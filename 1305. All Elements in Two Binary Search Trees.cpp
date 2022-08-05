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
    void traverse(TreeNode* root,vector<int>& res){
        if(!root)  
            return;
        traverse(root->left,res);
        res.push_back(root->val);
        traverse(root->right,res);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> res1;
        vector<int> res2;
        traverse(root1,res1);
        traverse(root2,res2);
    
        int n1 = res1.size();
        int n2 = res2.size();
        int x = 0;
        int y = 0;
        
        res1.push_back(INT_MAX);
        res2.push_back(INT_MAX);
        
        for(int i=0;i<(n1+n2);i++){
            if(res1[x] < res2[y])
                ans.push_back( res1[x++]);
            else
                ans.push_back(res2[y++]);
        }
        return ans;
    }
};
