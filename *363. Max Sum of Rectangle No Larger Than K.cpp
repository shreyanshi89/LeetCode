class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int rows = matrix.size();
        int col = matrix[0].size();
        
        for(int l=0;l<col;l++){
            vector<int> sums(rows);
            for(int r = l;r<col;r++){
                for(int i=0;i<rows;i++)
                    sums[i] += matrix[i][r];
                
                set<int> s = {0};
                int sum = 0;
                for(int num: sums){
                    sum += num;
                    auto it = s.lower_bound(sum - k);
                    if(it != end(s))
                        ans = max(ans,sum - *it);
                    s.insert(sum);
                }
            }
        }
        return ans;
    }
};
