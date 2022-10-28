class Solution {
public:
    
    int reverse(int n){
        int revs = 0;
        while(n){
            int rem = n % 10;
            revs = revs * 10 + rem;
            n /= 10;
        }
        return revs;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            nums.push_back(reverse(nums[i]));
            s.insert(nums[i]);
            s.insert(nums[n+i]);
        }
        return s.size();
    }
};
