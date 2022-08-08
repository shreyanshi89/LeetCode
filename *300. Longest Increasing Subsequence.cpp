class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(auto num:nums){
            if(ans.empty() || num>ans[ans.size() - 1])
                ans.push_back(num);
            else {
                int i = lower_bound(ans.begin(),ans.end(),num) - ans.begin();
                ans[i] = num;
            }
        }
        return ans.size();
    }
};
