class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> m;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++)
                m[i+j].push_back(mat[i][j]);
        }

        int i = 0;
        vector<int> ans; 
        for(auto num: m){
            if(i % 2 == 0)
                reverse(num.second.begin(), num.second.end());
            for(int i=0;i<num.second.size();i++)
                ans.push_back(num.second[i]);
            i++;
        }
        return ans;
    }
};
