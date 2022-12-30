class Solution {
public:

    void solution(int i, vector<int>& nums, vector<int> res, set<vector<int>>& ans){
        if(i >= nums.size()){
            if(res.size() > 1)
                ans.insert(res);
            return;
        }

        solution(i+1, nums, res, ans);
        if(res.empty() || res.back() <= nums[i])
            res.push_back(nums[i]);
        solution(i+1, nums, res, ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        solution(0, nums, {}, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
