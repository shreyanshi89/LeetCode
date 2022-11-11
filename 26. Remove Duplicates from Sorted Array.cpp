class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int j = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] != nums[i])
                nums[j++] = nums[i];
            
            else 
                ans++;
        }
        ans = nums.size() - ans;
        return ans;
    }
};
