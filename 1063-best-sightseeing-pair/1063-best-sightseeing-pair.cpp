class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int left_seed = values[0];
        int ans = 0;
        for (int i=1; i<n; i++) {
            ans = max(ans, values[i] + left_seed - 1);
            left_seed--;
            left_seed = max(left_seed, values[i]);
        }

        int right_seed = values[n-1];
        for (int i=n-2; i>=0; i--) {
            ans = max(ans, values[i] + right_seed - 1);
            right_seed--;
            right_seed = max(right_seed, values[i]);
        }

        return ans;
    }
};