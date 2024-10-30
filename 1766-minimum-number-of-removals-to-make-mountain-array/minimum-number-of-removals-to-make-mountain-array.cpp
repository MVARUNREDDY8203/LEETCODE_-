class Solution {
public:
    int dpf[1001];
    int dpb[1001];
    int lds_fwd(int prev, int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;

        if (dpf[prev] != -1) return dpf[prev];

        int ans = 0;
        if (nums[i] < nums[prev]) ans = max(ans, 1 + lds_fwd(i, i+1, nums));
        ans = max(ans, lds_fwd(prev, i+1, nums));

        return dpf[prev] = ans;
    }
    int lds_bck(int prev, int i, vector<int>& nums) {
        if (i < 0) return 0;  

        if (dpb[prev] != -1) return dpb[prev];

        int ans = 0;
        if (nums[i] < nums[prev]) ans = max(ans, 1 + lds_bck(i, i-1, nums));
        ans = max(ans, lds_bck(prev, i-1, nums));

        return dpb[prev] = ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        memset(dpf, -1, sizeof(dpf));
        memset(dpb, -1, sizeof(dpb));

        int ans = nums.size();
        for (int i=1; i<nums.size()-1; i++) {
            int b = lds_bck(i, i-1, nums);
            if (b == 0) continue;
            int f = lds_fwd(i, i+1, nums);
            if (f == 0) continue;
            int i_ans = nums.size() - (b + f + 1);
            ans = min(ans, i_ans);
        }
        return ans;
    }
};