class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());

        int i = 0;
        long long c = tasks[0][0];

        while(!pq.empty() || i<tasks.size()){
            while(i<tasks.size() && tasks[i][0] <= c){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if(pq.empty())
                c = tasks[i][0];

            else{
                pair<int,int> num = pq.top();
                c += num.first;
                ans.push_back(num.second);
                pq.pop();
            }
        }
        return ans;
    }
};
