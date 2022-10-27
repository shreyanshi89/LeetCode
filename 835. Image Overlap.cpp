class Solution {
public:

    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row, int col){
        int res = 0;
        int n = img1.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i + row < 0 || j + col < 0 || i + row >= n || j + col >= n))
                    continue;
                else if(img1[i][j] + img2[i+row][j+col] == 2)
                    res++;
            }
        }
        return res;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();

        for(int row=-n+1;row<n;row++){
            for(int col=-n+1;col<n;col++)
                ans = max(ans, overlap(img1, img2, row, col));
        }
        return ans;
    }
};
