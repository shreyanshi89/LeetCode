class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;

        for(int i=0;i<matches.size();i++){
            if(m.find(matches[i][0]) == m.end())
                m[matches[i][0]] = 0;
            m[matches[i][1]]++;
        }

        vector<int> res1;
        vector<int> res2;
        for(auto num: m){
            if(num.second == 0)
                res1.push_back(num.first);
            else if(num.second == 1)
                res2.push_back(num.first);
        }
        return {res1, res2};
    }
};
