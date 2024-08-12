class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pque;
    int m = 0;
    KthLargest(int k, vector<int>& nums) {
        for (auto i: nums) pque.push(i);
        while (pque.size() > k) pque.pop();
        m = k;
    }
    
    int add(int val) {
        if (pque.size() < m) pque.push(val);
        else {
            if (val > pque.top()) pque.push(val);
        }
        if (pque.size() > m) pque.pop();
        return pque.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */