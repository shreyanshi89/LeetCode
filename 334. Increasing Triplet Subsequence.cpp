// T.C. :- O(n)         S.C. :- O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX;
        int y = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(x >= nums[i])
                x = nums[i];
            
            else if(y >= nums[i])
                y = nums[i];
            
            else 
                return true;
        }
        return false;
    }
};


/*
    T.C. :- O(n)         S.C. :- O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] > res[res.size() - 1])
                res.push_back(nums[i]);
            else {
                int n = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[n] = nums[i];
            }
        }
        if(res.size() >= 3)
            return true;
        return false;
    }
};
*/
