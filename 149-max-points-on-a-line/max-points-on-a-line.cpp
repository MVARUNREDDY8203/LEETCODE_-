class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        for (int i=0; i<n; i++) {
            unordered_map<double, int> ump;
            for (int j=i+1; j<n; j++) {
                double m;
                int p = (points[j][1] - points[i][1]);
                int q = (points[j][0] - points[i][0]);
                if (q == 0) m = INT_MAX;
                else m = (double)p/(double)q;
                ump[m]++;
            }
            for (auto i: ump) ans = max(ans, i.second+1);
        }
        return ans;
    }
};