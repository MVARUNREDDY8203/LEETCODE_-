class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, max_weight = 0, n = weights.size();
        for (auto i: weights) sum += i, max_weight = max(i, max_weight);
        
        int r = sum, l = max_weight;
        while (l < r) {
            int mid_capacity = l + (r-l)/2;
            int curr_days = 1, tank = 0;
            for (int i=0; i<n; i++) {
                tank += weights[i];
                if (tank > mid_capacity) {
                    tank = weights[i];
                    curr_days++;
                }
            }

            if (curr_days > days) {
                l = mid_capacity+1;
            }
            else r = mid_capacity;
        }
        return l;
    }
};