// T.C. - O(n) & S.C. - O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        long long pre[n];
        
        for(int i=0;i<n;i++)
            pre[i] = nums[i];
            
        for(int i=0;i<n-1;i++)
            pre[i+1] += pre[i];
        
        for(int i=n-1;i>0;i--)
            nums[i-1] += nums[i];
        
        for(int i=0;i<n;i++){
            if(pre[i] == nums[i])
                return i;
            else continue;
        }
        return -1;
    }
};
