class Solution {
public:
    #define MOD 1000000007
    
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1] > b[1];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long ans = 0;
        vector<vector<int>> v;
        
        for(int i=0;i<n;i++)
            v.push_back({speed[i],efficiency[i]});
        sort(v.begin(),v.end(),comp);
        
        long s = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto num:v){
            pq.push(num[0]);
            s += num[0];
            if(pq.size() > k){
                s -= pq.top();
                pq.pop();
            }
            ans = max(ans, s * num[1]);
        }
        return ans % MOD;
    }
};
