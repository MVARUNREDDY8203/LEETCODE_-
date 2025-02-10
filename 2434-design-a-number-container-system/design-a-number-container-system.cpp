class NumberContainers {
public:
    NumberContainers() {
        
    }
    struct cmp {
        bool operator()(const int &a, const int &b) {
            return a > b;
        }
    };
    unordered_map<int, int> idx_num; // ground truth
    unordered_map<int, priority_queue<int, vector<int>, cmp>> num_idx;

    void change(int index, int number) {
        idx_num[index] = number;
        num_idx[number].push(index);
    }
    
    int find(int number) {
        if (!num_idx.count(number)) return -1;

        while (num_idx[number].size()) {
            int top_idx = num_idx[number].top();
            if (number == idx_num[top_idx]) return top_idx;
            num_idx[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */