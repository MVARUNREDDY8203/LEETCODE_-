class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = pos.size();
        vector<vector<double>> arr(n);
        for (int i=0; i<n; i++) {
            double time = (double)(target-pos[i])/(double)speed[i];
            arr[i] = {(double)pos[i], time};
        }
        sort(arr.begin(), arr.end(), [](const vector<double> &a, const vector<double>&b) {
            return a[0] < b[0];
        });
        stack<double> stk;
        stk.push(arr[n-1][1]);
        int i=n-2;
        while (i >= 0) {
            while (i>=0 && stk.top() >= (double)arr[i][1]) i--;
            if (i >=0) stk.push(arr[i][1]);
        }
        return stk.size();
    }
};