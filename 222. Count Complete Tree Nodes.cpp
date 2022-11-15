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

// T.C. - O(log(n)*log(n))
// S.C. - O(logn) (Auxiliary Stack Space)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = 0;
        int rh = 0;
        TreeNode* t = root;
        while(t){
            lh++;
            t = t->left;
        }

        t = root;
        while(t){
            rh++;
            t = t->right;
        }

        if(lh == rh)
            return pow(2, lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*  OR
//  T.C. - O(n)
//  S.C. - O(logn) (Auxiliary Stack Space)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;

        int a = countNodes(root->left);
        int b = countNodes(root->right);
        return a + b + 1;
    }
};
*/
