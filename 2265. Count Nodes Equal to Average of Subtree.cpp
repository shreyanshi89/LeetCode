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

    pair<int, int> traverse(TreeNode* root, int& ans, int& n){
        if(!root)
            return {0, 0};

        n++;
        auto left = traverse(root->left, ans, n);
        auto right = traverse(root->right, ans, n);

        if((left.first + right.first + root->val)/(left.second + right.second + 1) == root->val)
            ans++;
        cout<<left.first + right.first + root->val<<" ";
        return {root->val + left.first + right.first, left.second + right.second + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        int n = 0;
        traverse(root, ans, n);
        return ans;
    }
};
