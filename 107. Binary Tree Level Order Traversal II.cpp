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

    int depth(TreeNode* root){
        if(!root)
            return 0;

        return max(depth(root->left), depth(root->right)) + 1;
    }

    void traverse(TreeNode* root, vector<vector<int>>& ans, int level){
        if(!root)
            return;
        ans[level].push_back(root->val);
        traverse(root->left, ans, level-1);
        traverse(root->right, ans, level-1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d);
        traverse(root, ans, d-1);
        return ans;
    }
};
