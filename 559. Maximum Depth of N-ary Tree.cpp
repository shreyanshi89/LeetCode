/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;

        queue<Node*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                for(auto num: curr->children){
                    if(num)
                        q.push(num);
                }
            }
        }
        return level;
    }
};
