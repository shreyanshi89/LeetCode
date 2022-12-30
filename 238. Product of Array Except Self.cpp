class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int product = 1;
        
        bool b = false;
        int ind = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0 && b)
                return ans;
            
            else if(nums[i] == 0){
                b = true;
                ind = i;
            }

            else
                product *= nums[i];
        }
        
        if(b){
            ans[ind] = product;
            return ans;
        }

        for(int i=0;i<nums.size();i++)
            ans[i] = product / nums[i];
        
        return ans;
    }
};
