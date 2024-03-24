class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int sum = 0;
        for (int i=0; i<k; i++) sum += arr[i];
        int l = 0, r = k, n = arr.size(), ans = sum / k >= th ? 1 : 0;
        while (r < n) {
            sum += arr[r++];
            sum -= arr[l++];
            ans +=  sum / k >= th ? 1 : 0;
        }
        return ans;
    }
};