class Solution {
public:
    int days_calculator(vector<int>&weights, int max_load) {
        int days = 1, curr_load = 0;
        for (int i=0; i<weights.size(); i++) {
            curr_load += weights[i];
            if (curr_load > max_load) {
                days++;
                curr_load = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = -1, total = 0;
        for (auto i: weights) {
            total += i;
            max_weight = max(i, max_weight);
        }

        int l = max_weight, r = total, mid = 0;
        while (l < r) {
            mid = (l + r) / 2;
            int curr_days = days_calculator(weights, mid);
            cout<<l<<" "<<mid<<" "<<r<<" "<<curr_days<<endl;
            if (curr_days > days) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
            
        }
        return l;
    }
};