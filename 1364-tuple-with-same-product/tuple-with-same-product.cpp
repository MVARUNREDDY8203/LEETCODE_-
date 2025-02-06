class Solution {
public:
    unordered_map<int, long long int> fact_cache;
    long long int fact(int i) {
        if (i < 2) return 1;
        if (fact_cache.count(i)) return fact_cache[i];

        long long int ans = 1;
        for (int j=i; j>=2; j--) {
            ans *= j;
        }
        
        return fact_cache[i] = ans;
    }
    map<pair<int, int>, long long int> comb_cache;
    int combination(int n, int c) {
        if (comb_cache.count({n, c})) return comb_cache[{n, c}];

        return comb_cache[{n, c}] = fact(n) / (fact(n-c) * fact(c));
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