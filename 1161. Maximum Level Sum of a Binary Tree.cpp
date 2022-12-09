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
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int level = 0;
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            level++;
            int sum = 0;
            int size = q.size();

            for(int i=0;i<size;i++){
                auto num = q.front();
                q.pop();

                sum += num->val;
                if(num->left)
                    q.push(num->left);
                if(num->right)
                    q.push(num->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                ans = level;
            }
        }
        return ans;
    }
};
