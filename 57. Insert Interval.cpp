class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() < 1)
            return {newInterval};

        vector<vector<int>> ans;
        bool b = true;
        for(auto interval: intervals){
            if(newInterval[1] < interval[0]){
                if(b){
                    b = false;
                    ans.push_back({newInterval[0], newInterval[1]});
                }
                ans.push_back(interval);
            }
            
            else if(interval[1] < newInterval[0])
                ans.push_back(interval);
            
            else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        
        if(b)
            ans.push_back({newInterval[0], newInterval[1]});
        return ans;
    }
};
