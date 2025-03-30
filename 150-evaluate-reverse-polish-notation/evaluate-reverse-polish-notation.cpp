class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            string str = tokens[i];
            if(str == "/" || str == "*" || str == "+" || str == "-") { 
                if(str == "/") {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    int res = num2 / num1;
                    st.push(res); 
                }
                if(str == "*"){
                    int num1 = st.top(); // 9
                    st.pop();
                    int num2 = st.top(); // 3
                    st.pop();
                    int res = num2 * num1; // 3*9
                    st.push(res); // pushed 
                }
                if(str == "+") {
                    int num1 = st.top(); // 1
                    st.pop();
                    int num2 = st.top(); // 2
                    st.pop();
                    int res = num2 + num1; // 3
                    st.push(res); // pushed 3 in stack
                }
                if(str == "-") {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    int res = num2 - num1;
                    st.push(res);
                }
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
