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

    void sum(TreeNode* root, int& ans, int& res){
        if(!root)
            return;
        res = (res * 10 + root->val);
        if(!root->left && !root->right)
            ans += res;
        sum(root->left, ans, res);
        sum(root->right, ans, res);
        res /= 10;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int res = 0;
        sum(root, ans, res);
        return ans;
    }
};
