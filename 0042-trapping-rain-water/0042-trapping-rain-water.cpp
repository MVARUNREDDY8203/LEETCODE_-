class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> max_l(n, heights[0]);
        vector<int> max_r(n, heights[n-1]);
        for (int i=1; i<n; i++) {
            max_l[i] = max(max_l[i-1], heights[i-1]);
        }
        for (int i=n-2; i>=0; i--) {
            max_r[i] = max(max_r[i+1], heights[i+1]);
        }
        int ans = 0;

        for (int i=0; i<n; i++) {
            int temp = min(max_l[i], max_r[i]) - heights[i];
            if (temp > 0) ans += temp;
        }
        return ans;
    }
};