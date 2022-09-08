//  1) Recursive Traversal


/*
    2) Level Order Traversal
class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        if(!root)
            return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i=0;i<size;i++){
                auto num = q.front();
                q.pop();
                if(num->left)
                    q.push(num->left);
                if(num->right)
                    q.push(num->right);
                if(!num->left && !num->right)
                    return ans;
            }
        }
        return ans;
    }
};
*/
