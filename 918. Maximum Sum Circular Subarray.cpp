class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int>left(n,nums[0]);
        vector<int>right(n+1, 0);

        for(int i=1;i<n;i++)
            left[i] = left[i-1] + nums[i];
        
        right[0] = left[n-1];
        for(int i=1;i<n;i++)
            right[i] = right[i-1] - nums[i-1];
        
        int maxi = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(i > 0)
                maxi = max(maxi, left[i-1]);
            sum += nums[i];

            ans = max(ans, right[i+1]+nums[i]+maxi);
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
};
