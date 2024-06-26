class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (!min_stk.empty()) {
            if (min_stk.top() < val) min_stk.push(min_stk.top());
            else min_stk.push(val);
        }
        else min_stk.push(val);        
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
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