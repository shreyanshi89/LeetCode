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

#define MOD 1000000007
class Solution {
public:

    int sumTree(TreeNode* root){
        if(!root)
            return 0;

        int left = sumTree(root->left);
        int right = sumTree(root->right);

        return left + right + root->val;
    }

    int solution(TreeNode* root, long long sum, long long& ans){
        if(!root)
            return 0;

        int left = solution(root->left, sum, ans);
        int right = solution(root->right, sum, ans);
        
        ans = max({ans, (sum - left) * left, (sum - right) * right});
        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        long long ans = INT_MIN;
        long long sum = sumTree(root);
        solution(root, sum, ans);
        return ans % MOD;
    }
};
