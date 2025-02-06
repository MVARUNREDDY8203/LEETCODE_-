class Solution {
public:
    map<pair<int, int>, long long int> fact_cache;
    long long int fact(int n, int i) {
        if (n < 2) return 1;
        if (fact_cache.count({n, i})) return fact_cache[{n, i}];

        long long int ans = 1;
        for (int j=n; j>=i; j--) {
            ans *= j;
        }

        return fact_cache[{n, i}] = ans;
    }

    map<pair<int, int>, long long int> comb_cache;
    int combination(int n, int c) {
        if (comb_cache.count({n, c})) return comb_cache[{n, c}];

        return comb_cache[{n, c}] = fact(n, c+1) / fact(n-c, 1);
    }
    int tupleSameProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = nums.size();
        unordered_map<long long int, int> ump;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                long long curr = nums[i] * nums[j];
                ump[curr]++;
            }
        }

        int ans = 0;
        for (auto it: ump) {
            if (it.second < 2) continue;
            ans += combination(it.second, 2) * 8;
        }

        return ans;
    }
};