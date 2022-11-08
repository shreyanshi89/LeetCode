// T.C. - O(n) :- Using Stack

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.length();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            else if(abs(s[i] - st.top()) == 32)
                st.pop();
            else 
                st.push(s[i]);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*
  OR (Without using stack)
  class Solution {
  public:
    string makeGood(string s) {
        string ans = "";
        int n = s.length();

        for(int i=0;i<n;i++){
            ans.push_back(s[i]);

            while(ans.size() && abs(s[i+1] - ans.back()) == 32){
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};
*/
