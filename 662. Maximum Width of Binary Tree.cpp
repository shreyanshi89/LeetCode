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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, long long>> q;
        q.push({root,0});
        int width = 0;
        while(!q.empty()){
            int f;
            int l;
            int size = q.size();
            int min = q.front().second;
            for(int i=0;i<size;i++){
                long long num = q.front().second - min;
                auto curr = q.front().first;
                q.pop();

                if(i == 0)  f = num;
                if(i == size - 1)  l = num;

                if(curr->left)
                    q.push({curr->left,2*num + 1});
                if(curr->right)
                    q.push({curr->right,2*num + 2});
            }
            width = max(width,l - f + 1);
        }
        return width;
    }
};
