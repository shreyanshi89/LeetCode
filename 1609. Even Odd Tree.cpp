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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> res;
            for(int i=0;i<size;i++){
                auto curr = q.front();
                res.push_back(curr->val);
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            for(int i=0;i<res.size();i++){
                if(level % 2 == 0){
                    if(res[i] % 2 == 0)
                        return false;
                }
                else {
                    if(res[i] % 2 != 0)
                        return false;
                }
            }
            for(int i=1;i<res.size();i++){
                if(level % 2 == 0){
                    if(res[i-1] >= res[i])
                        return false;
                }
                else {
                    if(res[i-1] <= res[i])
                        return false;
                }
            }
            level++;
        }
        return true;
    }
};
