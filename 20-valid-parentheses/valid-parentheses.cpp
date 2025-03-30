class Solution {
public:
    bool isValidParentheses(char top, char ch) {
        if ((top == '(' && ch == ')') || (top == '[' && ch == ']') ||
            (top == '{' && ch == '}'))
            return true;
        return false;
    }
    
    bool isValid(string exp) {
        stack<char> st;

        for (int i = 0; i < exp.length(); i++) {
            if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
                st.push(exp[i]);
            }
            else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
                if (st.empty() || !isValidParentheses(st.top(), exp[i])) 
                    return false;
                st.pop(); 
            }
        }
        
        return st.empty();  
    }
};