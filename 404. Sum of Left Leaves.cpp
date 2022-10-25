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

    void traverse(TreeNode* root, int& sum, int n){
        if(!root)
            return;
        
        if(n && !root->left && !root->right)
            sum += root->val;
        traverse(root->left, sum, 1);
        traverse(root->right, sum, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverse(root, sum, 0);
        return sum;
    }
};
