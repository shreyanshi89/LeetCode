// O(n)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for(int num: nums)
            res += m[num]++;
        return res;
    }
};
