class Solution {
public:

    int nextTree(vector<int> a,vector<int> b,vector<int> c){
        return ((c[1] - a[1])*(b[0]-a[0])) - ((c[0] - a[0])*(b[1]-a[1]));
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <= 3)
            return trees;
        sort(trees.begin(), trees.end());

        vector<vector<int>> tree;
        tree.push_back(trees[0]);
        tree.push_back(trees[1]);

        for(int i=2;i<trees.size();i++){
            int size = tree.size();
            while(tree.size() >= 2 && nextTree(tree[size-2],tree[size-1],trees[i]) > 0){
                tree.pop_back();
                size--;
            }
            tree.push_back(trees[i]);
        }

        vector<vector<int>> tree2;
        tree2.push_back(trees[trees.size() - 1]);
        tree2.push_back(trees[trees.size() - 2]);

        for(int i=trees.size()-3;i>=0;i--){
            int size = tree2.size();
            while(tree2.size() >= 2 && nextTree(tree2[size-2],tree2[size-1],trees[i]) > 0){
                tree2.pop_back();
                size--;
            }
            tree2.push_back(trees[i]);
        }

        tree.pop_back();
        tree2.pop_back();

        for(int i=0;i<tree2.size();i++)
            tree.push_back(tree2[i]);

        sort(tree.begin(),tree.end());
        tree.erase(std:: unique(tree.begin(), tree.end()), tree.end());
        return tree;
    }
};
