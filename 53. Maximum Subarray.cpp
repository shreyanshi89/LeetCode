// T.C. -> O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int sum = 0;
        int m = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] > m)
                m = nums[i];
        }
        if(m < 1)
            return m;
        
	    for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            maxSum = max(maxSum,sum);
	    }
        return maxSum;
    }
};
