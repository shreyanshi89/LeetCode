class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        int arrow = 0;
        sort(points.begin(), points.end(), comp);
        
        for(auto num: points){
            if(ans == 0 || arrow < num[0]){
                ans++;
                arrow = num[1];
            }
        }
        return ans;
    }
};
