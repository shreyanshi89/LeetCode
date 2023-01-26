class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n, INT_MAX);
        res[src] = 0;

        for(int i=0;i<=k;i++){
            vector<int> m(res.begin(), res.end());
            for(auto f: flights){
                int curr = f[0];
                int next = f[1];
                int cost = f[2];

                if(res[curr] == INT_MAX)
                    continue;
                m[next] = min(m[next], res[curr] + cost);
            }
            res = m;
        }
        return res[dst] == INT_MAX? -1:res[dst];
    }
};
