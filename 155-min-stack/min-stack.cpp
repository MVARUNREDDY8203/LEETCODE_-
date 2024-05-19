class MinStack {
public:
    stack<int> real_stk;
    stack<int> min_stk;
    MinStack() {
    }
    
    void push(int val) {
        real_stk.push(val);
        if (min_stk.size() > 0) min_stk.push(min_stk.top() > val ? val : min_stk.top());
        else min_stk.push(val);
    }
    
    void pop() {
        real_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return real_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
