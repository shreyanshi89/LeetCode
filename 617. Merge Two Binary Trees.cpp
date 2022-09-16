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
    
    void merge(TreeNode*& root,TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2)
            return;
        
        else if(root1 && root2){
            TreeNode* ptr = new TreeNode(root1->val+root2->val);
            root = ptr;
            merge(root->left,root1->left,root2->left);
            merge(root->right,root1->right,root2->right);
        }
        else if(root1 && !root2){
            TreeNode* ptr = new TreeNode(root1->val);
            root = ptr;
            merge(root->left,root1->left,root2);
            merge(root->right,root1->right,root2);
        }
        else if(!root1 && root2){
            TreeNode* ptr = new TreeNode(root2->val);
            root = ptr;
            merge(root->left,root1,root2->left);
            merge(root->right,root1,root2->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = NULL;
        merge(root,root1,root2);
        return root;
    }
};
