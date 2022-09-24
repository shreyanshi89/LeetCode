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
    vector<int> v;
    void traverse(TreeNode* root,int target,vector<vector<int>>& ans,int& sum){
        if(!root)
            return;
        
        sum += root->val;
        v.push_back(root->val);
        if(sum == target && (!root->left && !root->right))
            ans.push_back(v);
        
        traverse(root->left,target,ans,sum);
        traverse(root->right,target,ans,sum);
        sum -= root->val;
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        traverse(root,targetSum,ans,sum);
        return ans;
    }
};
