class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for(auto num: tokens){
            if(num != "+" && num != "-" && num != "*" && num != "/")
                st.push(stoi(num));

            else{
                long long num2 = st.top();
                st.pop();
                long long num1 = st.top();
                st.pop();

                if(num == "+")
                    st.push(num1 + num2);
                else if(num == "-")
                    st.push(num1 - num2);
                else if(num == "*")
                    st.push(num1 * num2);
                else
                    st.push(num1 / num2);
            }
        }
        return st.top();
    }
};
