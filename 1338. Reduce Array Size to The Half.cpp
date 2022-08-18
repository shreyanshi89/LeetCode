class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans = 0;
        
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        
        priority_queue<int> q;
        for(auto num:m)
            q.push(num.second);
        
        int ctr = 0;
        while(ctr < arr.size()/2){
            ctr += q.top();
            q.pop();
            ans++;
        }
        return ans;
    }
};
