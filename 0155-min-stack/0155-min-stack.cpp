class MinStack {
private:
    stack<int> st;
    stack<int> min_stack;
public:

    void push(int val) {
        st.push(val);
        if(min_stack.empty() || val <= min_stack.top()){
            min_stack.push(val);
        }
        
    }
    
    void pop() {
        if(st.top() == min_stack.top()) min_stack.pop();
        if(!st.empty()) st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top();
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