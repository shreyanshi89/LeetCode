// O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            int num = target - nums[i];
            if(m.find(num) != m.end()){
                return {m.find(num)->second,i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
