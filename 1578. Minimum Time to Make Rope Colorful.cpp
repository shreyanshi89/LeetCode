class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int ans = 0;
        int time = neededTime[0];
        int m = neededTime[0];
        for(int i=1;i<n;i++){
            if(colors[i] != colors[i-1]){
                ans += (time - m);
                time = 0;
                m = 0;
            }
            time += neededTime[i];
            m = max(m,neededTime[i]);
        }
        ans += (time - m);
    return ans;
    }
};
