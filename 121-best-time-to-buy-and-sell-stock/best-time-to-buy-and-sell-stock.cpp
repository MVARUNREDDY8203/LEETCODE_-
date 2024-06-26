class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = prices.size();
        vector<int> next_max(n, prices[n-1]);
        for (int i=n-2; i>=0; i--) next_max[i] = max(next_max[i+1], prices[i]);
        int ans = 0;
        for (int i=0; i<=n-2; i++) {
            ans = max(ans,next_max[i] -  prices[i]);
        }
        return ans;
    }
};