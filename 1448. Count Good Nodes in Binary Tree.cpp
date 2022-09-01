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
    
    void preorder(TreeNode* root,int& ctr,int max){
        if(!root)
            return;
        if(root->val >= max){
            max = root->val;
            ctr++;
        }
        preorder(root->left,ctr,max);
        preorder(root->right,ctr,max);
    }
    
    int goodNodes(TreeNode* root) {
        int ctr = 0;
        int max = root->val;
        preorder(root,ctr,max);
        return ctr;
    }
};
