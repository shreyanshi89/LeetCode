class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans(image.size(), vector<int> (image[0].size() ,0));

        for(int i=0;i<image.size();i++){
            for(int j=image[0].size()-1;j>=0;j--){
                if(!image[i][j])
                    ans[i][image.size() - 1 - j] = 1;
            }
        }
        return ans;
    }
};
