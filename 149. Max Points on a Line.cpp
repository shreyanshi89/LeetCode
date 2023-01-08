class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 2)
            return 1;
        int ans = 0;

        for(int i=0;i<points.size();i++){
            unordered_map<float, int> m;

            for(int j=0;j<points.size();j++){
                if(points[i][0] - points[j][0] > 0)
                    m[(float)(points[i][1] - points[j][1]) / (float)(points[i][0] - points[j][0])]++;

                else if(i != j && points[i][0] == points[j][0])
                    m[INT_MAX]++;
            }
            
            int maxi = 0;
            for(auto num: m){
                if(num.second > maxi)
                    maxi = num.second;
            }
            ans = max(ans, maxi);
        }
        return ans+1;
    }
};
