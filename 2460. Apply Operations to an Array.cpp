class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;        
            }
        }
        int j = 0;
        for(int n: nums){
            if(n)
                nums[j++] = n;
        }
        nums.resize(j);
        nums.resize(size);
        return nums;
    }
};
