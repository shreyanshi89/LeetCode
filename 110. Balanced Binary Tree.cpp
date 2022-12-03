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

    int depth(TreeNode* root, bool& b){
        if(!root) 
            return 0;
        
        int left = depth(root->left, b);
        int right = depth(root->right, b);

        if(abs(left - right) > 1)
            b = false;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) 
            return true;
        
        bool b = true;
        depth(root, b);
        return b;
    }
};
