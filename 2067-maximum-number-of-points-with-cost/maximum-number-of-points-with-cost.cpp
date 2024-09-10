class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> prev_row(n);
        for (int j=0; j<n; j++) {
            prev_row[j] = points[0][j];
        }

        vector<long long> curr_row(n);
        for (int i=0; i<m-1; i++) {
            vector<long long> left_max(n);
            vector<long long> right_max(n);

            left_max[0] = prev_row[0];
            for (int j=1; j<n; j++) {
                left_max[j] = max(left_max[j-1]-1, prev_row[j]);
            }

            right_max[n-1] = prev_row[n-1];
            for (int j=n-2; j>=0; j--) {
                right_max[j] = max(right_max[j+1]-1, prev_row[j]);
            }

            for (int j=0; j<n; j++) {
                curr_row[j] = points[i+1][j] + max(left_max[j], right_max[j]);
            }

            prev_row = curr_row;
        }

        long long ans = 0;
        for (int j=0; j<n; j++) {
            ans = max(ans, prev_row[j]);
        }

        return ans;
    }
};