class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i = 0;
        int ans = 0;
        priority_queue<int> pq;
        
        for(ans = 0;startFuel < target;ans++){
            while(i < stations.size() && startFuel >= stations[i][0])
                pq.push(stations[i++][1]);
            
            if(pq.empty())
                return -1;
            
            startFuel += pq.top();
            pq.pop();
        }
        return ans;
    }
};
