// 1) Recursive Traversal

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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};

/*

2) Level Order Traversal
    --> Extra O(n) space complexity for storing nodes in the queue DS.

class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i=0;i<size;i++){
                auto num = q.front();
                q.pop();
                if(num->left)
                    q.push(num->left);
                if(num->right)
                    q.push(num->right);
            }
        }
        return ans;
    }
};
*/
