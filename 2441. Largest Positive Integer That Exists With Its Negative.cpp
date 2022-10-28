class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        int ans = -1;
        
        for(int num: nums){
            s.insert(num);
            if(s.find(-num) != s.end())
                ans = max(ans, abs(num));
        }
        if(ans != -1)
            return ans;
        return -1;
    }
};
