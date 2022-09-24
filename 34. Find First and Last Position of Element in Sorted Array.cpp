// O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = -1;
        int b = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target && a == -1)
                a = i;
            if(nums[i] == target)
                b = i;
        }
        return {a,b};
    }
};
