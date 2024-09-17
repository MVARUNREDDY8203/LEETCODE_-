class Solution {
public:
    int findMinDifference(vector<string>& arr) {
        int n = arr.size();
        vector<int> cvt;

        for (int i=0; i<n; i++) {
            int hrs =(arr[i][0] - '0') * 10 + (arr[i][1]);
            int mins = hrs * 60;
            mins += 10 * (arr[i][3]) + arr[i][4];
            cvt.push_back(mins);
        }

        sort(cvt.begin(), cvt.end());
        int ans = INT_MAX;
        for (int i=1; i<cvt.size(); i++) {
            ans = min(ans, cvt[i] - cvt[i-1]);
        }
        ans = min(ans, 1440 - (cvt[cvt.size() - 1] - cvt[0]));
        return ans;
    }
};