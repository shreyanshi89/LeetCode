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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            bool bx = false;
            bool by = false;
    
            int size = q.size();
            for(int i=0;i<size;i++){
                auto num = q.front();
                q.pop();
                
                if(num->right && num->left){
                    if(num->left->val == x && num->right->val == y || num->left->val == y && num->right->val == x)
                        return false;
                }
                if(num->left){
                    q.push(num->left);
                    if(num->left->val == x)
                        bx = true;
                    if(num->left->val == y)
                        by = true;
                }
                if(num->right){
                    q.push(num->right);
                    if(num->right->val == x)
                        bx = true;
                    if(num->right->val == y)
                        by = true;
                }
            }
            if(bx && by)
                return true;
        }
        return false;
    }
};
