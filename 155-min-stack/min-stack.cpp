class MinStack {
public:
    stack<long long> st;
    long long min = INT_MAX;
    MinStack() {}

    void push(int val) {
        if (val >= min)
            st.push(val);
        else {
            st.push(2LL * val - min);
            min = val;
        }
    }

    void pop() {
        long long top = st.top();
        st.pop();
        if (top < min)
            min = 2LL * min - top;
    }

    int top() {
        if (st.empty())
            return -1;
        long long top = st.top();
        if (top >= min)
            return top;
        else
            return min;
    }

    int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */