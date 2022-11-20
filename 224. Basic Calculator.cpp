class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        int num = 0;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i]))
                num = num*10 + (s[i] - '0');
            else if(s[i] == '+'){
                ans += (num * sign); 
                sign = 1;
                num = 0;
            }
            else if(s[i] == '-'){
                ans += (num * sign);
                sign = -1;
                num = 0;
            }

            else if(s[i] == '('){
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
                num = 0;
            }

            else if(s[i] == ')'){
                ans += (num*sign);
                num = 0;
                ans = ans * st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
        }
        ans += (num * sign); 
        return ans;      
    }
};
