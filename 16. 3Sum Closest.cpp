// T.C. :- O(n^2)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int low = i+1;
            int high = nums.size() - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == target)
                    return target;
                else if(sum < target)
                    low++;
                else 
                    high--;
                if(abs(target - sum) < diff){
                    diff = abs(target - sum);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
