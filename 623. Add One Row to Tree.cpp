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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* ptr = new TreeNode(val);
            ptr->left = root;
            return ptr;
        }

        queue<TreeNode*> q;
        vector<TreeNode*> res;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            level++;
            if(level == depth - 1)
                break;
            for(int i=0;i<n;i++){
                auto p = q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }
        while(!q.empty()){
            TreeNode* n1 = new TreeNode(val);
            TreeNode* n2 = new TreeNode(val);
            n1->left = q.front() -> left;
            q.front()->left = n1;
            n2->right = q.front() -> right;
            q.front()->right = n2;
            q.pop();
        }
        return root;
    }
};
