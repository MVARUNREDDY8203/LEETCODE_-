class MinStack {
    Stack<Integer> real_stk= new Stack<>();
    Stack<Integer> min_stk= new Stack<>();
    public MinStack() {

    }
    
    public void push(int val) {
        real_stk.push(val);
        if (!min_stk.isEmpty()) min_stk.push(Math.min(min_stk.peek(), val));
        else min_stk.push(val);
    }
    
    public void pop() {
        real_stk.pop();
        min_stk.pop();
    }
    
    public int top() {
        return real_stk.peek();
    }
    
    public int getMin() {
        return min_stk.peek();
    }
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */