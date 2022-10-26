class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        int sum = 0;
        m[sum % k]++;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int n = sum % k;
            if(n < 0)
                n = n + k;
            if(m.find(n) != m.end())  
                ans += m[n];
            m[n]++;
        }
        return ans;
    }
};
