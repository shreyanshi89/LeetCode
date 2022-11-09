class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;
        st.push({temperatures[n-1], 0});

        for(int i=temperatures.size() - 2;i>=0;i--){
            int ctr = 0;
            while(!st.empty() && temperatures[i] >= st.top().first){
                ctr += st.top().second;
                st.pop();
            }
            if(st.empty())
                ctr = 0;
            else 
                ctr++;
            st.push({temperatures[i],ctr});
            ans[i] = ctr;
        }
        return ans;
    }
};
