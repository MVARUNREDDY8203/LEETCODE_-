class Solution {
public:
    typedef long long int ll;
    const int mod = 1e9 + 7;
    int dp[201][201][201];
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    int util(int i, int gcd1, int gcd2, vector<int>&nums) {
        if (i == nums.size()) return (gcd1 == gcd2) && (gcd1 && gcd2);

        if (dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];

        ll ans = 0;
        ll dont_take = util(i+1, gcd1, gcd2, nums);
        ll take1 = util(i+1, gcd(gcd1, nums[i]), gcd2, nums);
        ll take2 = util(i+1, gcd1, gcd(gcd2, nums[i]), nums);

        return dp[i][gcd1][gcd2] = (dont_take + take1 + take2) % mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return util(0, 0, 0, nums);
    }
};