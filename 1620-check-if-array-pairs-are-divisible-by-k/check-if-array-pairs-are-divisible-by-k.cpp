class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        unordered_map<int, int> ump;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            arr[i] = ((arr[i] % k) + k) % k;
            ump[arr[i]]++; 
        }
        int l = 1, r = k-1;
        while (l <= r) {
            if (l == r) {
                return ump[l] % 2 == 0;
            }
            if (ump[l] != ump[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};