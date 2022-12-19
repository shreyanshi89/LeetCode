class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, vector<int>> m;

        for(auto num: edges){
            m[num[0]].push_back(num[1]);
            m[num[1]].push_back(num[0]);
        }

        vector<bool> vis(n,false);
        stack<int> st;
        st.push(source);

        while(!st.empty()){
            auto g = st.top();
            vis[g] = true;
            st.pop();

            if(g == destination)
                return true;

            for(auto num: m[g]){
                if(!vis[num])
                    st.push(num);
            }
        }
        return false;
    }
};
