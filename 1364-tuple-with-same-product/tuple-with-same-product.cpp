class Solution {
public:
    unordered_map<int, long long int> fact_cache;
    long long int fact(int i) {
        if (i < 2) return 1;
        if (fact_cache.count(i)) return fact_cache[i];

        return fact_cache[i] = i * fact(i-1);
    }
    int combination(int n, int c) {
        return fact(n) / (fact(n-c) * fact(c));
    }
    int tupleSameProduct(vector<int>& nums) {
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
            cout<<it.first<<" "<<it.second<<endl;
            ans += combination(it.second, 2) * 8;
        }

        return ans;
    }
};