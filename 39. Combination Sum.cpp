class Solution {
public:
    vector<int> v;
    void comSum(vector<int>& candidates, int target, vector<vector<int>>& ans, int start){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        else if(target < 0)
            return;
        
        for(int i=start;i<candidates.size()&& target >= candidates[i];i++){
            v.push_back(candidates[i]);
            comSum(candidates,target - candidates[i],ans,i);
            v.pop_back();    
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        comSum(candidates,target,ans,0);
        return ans;
    }
};
