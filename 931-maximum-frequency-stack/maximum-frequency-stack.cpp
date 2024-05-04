class FreqStack {
private:
    unordered_map<int, vector<int>> cnt_stack;
    unordered_map<int, int> freq;
    vector<int> max_freq_stack;
public:
    FreqStack() {
        max_freq_stack.push_back(0);
    }
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > max_freq_stack.back()) max_freq_stack.push_back(freq[val]);
        cnt_stack[freq[val]].push_back(val);
    }
    
    int pop() {
        int cnt_most_freq_element = max_freq_stack.back();
        int val_most_freq_element = cnt_stack[cnt_most_freq_element].back();

        freq[val_most_freq_element]--;
        cnt_stack[cnt_most_freq_element].pop_back();
        if (cnt_stack[cnt_most_freq_element].size() == 0) max_freq_stack.pop_back();

        return val_most_freq_element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */