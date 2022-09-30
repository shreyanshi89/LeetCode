class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> res;

        for(auto b:buildings){
            res.push_back({b[0],-b[2]});
            res.push_back({b[1],b[2]});
        }
        sort(res.begin(),res.end());

        multiset<int> s{0};
        int prev = 0;
        for(int i=0;i<res.size();i++){
            if(res[i].second < 0)
                s.insert(-res[i].second);
            else
                s.erase(s.find(res[i].second));
            
            auto curr = *s.rbegin();
            if(prev != curr){
                prev = curr;
                ans.push_back({res[i].first,prev});
            }
        }
        return ans;
    }
};
