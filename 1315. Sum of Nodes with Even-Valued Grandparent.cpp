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

    void traverse(TreeNode* root,int& sum, TreeNode* gp, TreeNode* p){
        if(!root)
            return;

        if(p && gp && gp->val % 2 == 0)
            sum += root->val;
        traverse(root->left,sum,p,root);
        traverse(root->right,sum,p,root);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        traverse(root,sum,NULL,NULL);
        return sum;
    }
};
