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

    int traverse(TreeNode* root, int maxi, int mini){
        if(!root)
            return abs(mini - maxi);

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        int left = traverse(root->left, maxi, mini);
        int right = traverse(root->right, maxi, mini);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return traverse(root, -100000, 100000);
    }
};
