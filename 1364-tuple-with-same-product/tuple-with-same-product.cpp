class Solution {
public:
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
            ans += ((it.second * (it.second - 1)) / 2) * 8;
        }

        return ans;
    }
};