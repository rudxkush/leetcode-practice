class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            bool isAlive = true; // assuming it doesn't collide
            while(!st.empty() && st.top() > 0 && ast[i] < 0) {
                if(-ast[i] > st.top()) {
                    st.pop();
                    continue;
                } else if(-ast[i] == st.top()){
                    st.pop();
                }
                isAlive = false;
                break;
            }
            if(isAlive) {
                st.push(ast[i]);
            }
        }
        int survived = st.size() - 1;
        vector<int> astW(survived + 1);
        while (!st.empty()) {
            astW[survived] = st.top();
            survived--;
            st.pop();
        }
        return astW;
    }
};
/*
        Think of all the edge cases
    + -> Right          - -> Left
    1. Right collides with Left
        - (Right.val < Left.val) { gets destroyed and next right is faced}
        - (Right.val == Left.val) { gets completely destroyed along with right}
        - (Right.val > Left.val) { doesn't get destroyed }
    2. No Right and you get a Left
        - skip!!
*/