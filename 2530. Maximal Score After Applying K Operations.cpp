class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        
        for(int i=0;i<k;i++){
            int res = pq.top();
            pq.pop();
            ans += res;
            pq.push(ceil(res/3.0));
        }
        return ans;
    }
};
