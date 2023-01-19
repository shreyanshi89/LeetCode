class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = nums.size();
        int need = 0;
        for(auto num: nums)
            need = (need + num) % p;

        int curr = 0;
        unordered_map<int, int> m = {{0,-1}};
        for(int i=0;i<nums.size();i++){
            curr = (curr + nums[i]) % p;
            m[curr] = i;

            int req = (curr - need + p) % p;
            if(m.count(req))
                ans = min(ans, i - m[req]);
        }
        return ans == nums.size()? -1:ans;
    }
};
