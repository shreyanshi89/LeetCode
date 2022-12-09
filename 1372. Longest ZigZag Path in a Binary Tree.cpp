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

    void traverse(TreeNode* root, int& ans, bool prevL, bool prevR, int res){
        if(!root)
            return;
        ans = max(res, ans);
        
        if(root->left && prevL)
            traverse(root->left, ans, true, false, 1);
        else if(root->left)
            traverse(root->left, ans, true, false, res+1);

        if(root->right && prevR)
            traverse(root->right, ans, false, true, 1);
        else if(root->right)
            traverse(root->right, ans, false, true, res+1);
    }

    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        traverse(root, ans, false, false, 0);
        return ans;
    }
};
