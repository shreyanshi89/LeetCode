class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        int res = INT_MAX;
        int ans = 0;
        vector<long long> right(n,nums[n-1]);

        for(int i=n-2;i>=0;i--)
            right[i] = right[i+1] + nums[i];
        right.push_back(0);
        
        long long left = 0;
        for(int i=0;i<n;i++){
            int curr;
            left += nums[i];
            if(n-i-1 > 0)
                curr = abs((left /(i+1)) - (right[i+1]/(n-i-1)));
        
            else
                curr = left /(i+1);

            if(curr < res){
                res = curr;
                ans = i;
            }
        }
        return ans;
    }
};
