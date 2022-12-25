class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());

        vector<int> ans(m);
        for(int j=0;j<m;j++){
            int sum = 0;
            int size = 0;

            for(int i=0;i<n;i++){
                if(sum + nums[i] <= queries[j]){
                    sum += nums[i];
                    size++;
                }
            }
            ans[j] = size;
        }
        return ans;
    }
};
