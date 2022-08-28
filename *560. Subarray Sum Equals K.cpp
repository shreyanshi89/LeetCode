class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        
        map<int, int> m;
        m[sum] = 1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            auto it = m.find(sum - k);
            
            if(it != m.end())
                ans += m[sum - k];
            
            m[sum]++;
        }
        return ans;
    }
};
