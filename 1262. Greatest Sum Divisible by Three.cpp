class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mo = 10000;
        int mod = 10000;
        int mt = 10000;
        int mtd = 10000;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(nums[i] %  3 == 1){
                if(mo > nums[i]){
                    mod = mo;
                    mo = nums[i];
                }
                else if(nums[i] < mod)
                    mod = nums[i];
            }
            if(nums[i] %  3 == 2){
                if(mt > nums[i]){
                    mtd = mt;
                    mt = nums[i];
                }
                else if(nums[i] < mtd)
                    mtd = nums[i];
            }
        }
        if(sum % 3 == 0)
            return sum;
        else if(sum % 3 == 1)
            return sum - min(mo,mt+mtd);
        return sum - min(mt,mo+mod);
    }
};
