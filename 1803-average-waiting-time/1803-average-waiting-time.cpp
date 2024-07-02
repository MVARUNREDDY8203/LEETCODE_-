class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int at = 1, ct = 0, n = customers.size(), wt_sum = 0;
        for (int i=0; i<n; i++) {
            vector<int> &t = customers[i];
            if (t[0] < ct) {
                wt_sum += (ct-t[0]);
                ct += t[1];
            }
            else {
                ct = t[0] + t[1];
            }
            wt_sum += (t[1]);
        }
        cout<<wt_sum;
        return double(wt_sum)/(double)n;
    }
};