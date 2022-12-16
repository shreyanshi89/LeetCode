class Solution {
public:

    bool traverse(vector<vector<int>>& matrix, int i, int j, int target){
        if(i >= matrix.size() || j < 0)
            return false;

        if(target == matrix[i][j])
            return true;
            
        if(target < matrix[i][j])
            return traverse(matrix, i, j - 1, target);
        
        if(target > matrix[i][j])
            return traverse(matrix, i + 1, j, target);
        
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return traverse(matrix, 0, matrix[0].size() - 1, target);
    }
};
