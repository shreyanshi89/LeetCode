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

        if(!root->left && !root->right)
            res.push_back(root->val);

        traverse(root->left,res);
        traverse(root->right,res);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        traverse(root1,res1);
        traverse(root2,res2);

        if(res1.size() != res2.size())
            return false;

        for(int i=0;i<res1.size();i++){
            if(res1[i] != res2[i])
                return false;
        }
        return true;
    }
};
