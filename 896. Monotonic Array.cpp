class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false;
        bool dec = false;

        for(int i=0;i<nums.size()-1;i++){
            if(!inc && !dec && nums[i] < nums[i+1])   inc = true;
            else if(!inc && !dec && nums[i] > nums[i+1]) dec = true;
            else if(inc && nums[i] > nums[i+1] || dec && nums[i] < nums[i+1])
                return false;
        }
        return true;
    }
};
