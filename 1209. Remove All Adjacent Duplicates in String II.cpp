class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        stack<pair<char, int>> st;

        for(int i=0;i<s.length();i++){
            if(st.size() && st.top().first == s[i])
                st.top().second++;
            else 
                st.push({s[i], 1});

            if(st.size() && st.top().second == k)
                st.pop();
        }
        while(!st.empty()){
            int n = st.top().second;
            for(int i=0;i<n;i++)
                ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
