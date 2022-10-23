class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        vector<int> res(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            res[nums[i]]++;
        }

        for(int i=1;i<res.size();i++){
            if(res[i] == 2)
                ans[0] = i;
            else if(res[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
};
