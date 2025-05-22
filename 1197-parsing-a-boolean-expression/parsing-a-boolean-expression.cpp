class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> bracket;
        stack<char> operation;

        for (char exp : expression) {
            if (exp == ',')
                continue;
            else if (exp == '(' || exp == 't' || exp == 'f') {
                bracket.push(exp);
            } else if (exp == '!' || exp == '&' || exp == '|') {
                operation.push(exp);
            } else if (exp == ')') {
                vector<char> operands;
                while (!bracket.empty() && bracket.top() != '(') {
                    operands.push_back(bracket.top());
                    bracket.pop();
                }
                if (!bracket.empty())
                    bracket.pop();

                char oper = operation.top();
                operation.pop();

                char result;
                if (oper == '!') {
                    result = operands[0] == 't' ? 'f' : 't';
                } else if (oper == '&') {
                    result = 't';
                    for (char c : operands) {
                        if (c == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } else if (oper == '|') {
                    result = 'f';
                    for (char c : operands) {
                        if (c == 't') {
                            result = 't';
                            break;
                        }
                    }
                }

                bracket.push(result);
            }
        }

        return bracket.top() == 't';
    }
};
