class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> res;

        for(int i=0;i<rocks.size();i++)
            res.push_back(capacity[i] - rocks[i]);
        
        sort(res.begin(), res.end());

        int i = 0;
        for(i=0;i<rocks.size() && additionalRocks >= res[i];i++)
            additionalRocks -= res[i];
        
        return i;
    }
};
