class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int fuel = 0;
        int tank = 0;
        int ans = 0;

        for(int i=0;i<size;i++){
            fuel += (gas[i] - cost[i]);
            tank += (gas[i] - cost[i]);
            if(tank < 0){
                tank = 0;
                ans = i+1;
            }
        }
        if(fuel >= 0)
            return ans;
        return -1;
    }
};
