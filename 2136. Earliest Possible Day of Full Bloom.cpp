class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        multimap<int, int> m;

        for(int i=0;i<n;i++)
            m.insert({growTime[i], plantTime[i]});

        int a = -1;
        int maxi = 0;
        while(!m.empty()){
            auto num = prev(m.end());
            a += num->second;
            maxi = max(maxi,num->first + a + 1);
            m.erase(prev(m.end()));
        }
        return maxi;
    }
};
