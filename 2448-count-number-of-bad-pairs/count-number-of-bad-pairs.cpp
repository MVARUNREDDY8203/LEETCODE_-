class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        long long n = nums.size(), ans = (n * (n-1))/2, good_pairs = 0;
        unordered_map<int, int> ump;
        for (int i=0; i<n; i++) {
            ump[i - nums[i]]++;
        }
        for (auto it: ump) {
            if (it.second > 1) {
                good_pairs += (long long)(((long long)it.second * (long long)(it.second - 1)) / (long long)2) ;
            }
        }
        return ans - good_pairs;
    }
};