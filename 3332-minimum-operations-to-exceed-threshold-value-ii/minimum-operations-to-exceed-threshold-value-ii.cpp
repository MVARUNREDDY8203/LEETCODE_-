class Solution {
public:
    struct cmp {
        bool operator()(long long int &a, long long int &b) {
            return a > b;
        }
    };
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, cmp> pq;
        for (auto i: nums) pq.push(i);

        int cnt = 0;
        while (pq.top() < k) {
            cnt++;
            long long int one = pq.top();
            pq.pop();
            long long int two = pq.top();
            pq.pop();

            pq.push((long long int)min(one, two) * (long long int)2 + (long long int)max(one, two));
        }
        return cnt;
    }
};