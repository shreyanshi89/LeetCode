class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =  matrix.size();

        for(int i=1;i<n;i++){
           for(int j=0;j<n;j++){
               matrix[i][j] += min({matrix[i-1][j], matrix[i-1][max(0, j-1)], matrix[i-1][min(n-1, j+1)]});
            } 
        }
        int min = INT_MAX;
        for(int i=0;i<n;i++){
            if(matrix[n-1][i] < min)
                min = matrix[n-1][i];
        }
        return min;
    }
};
