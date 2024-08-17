class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int m = arr.size();
        int hv = arr[0].back();
        int lv = arr[0][0];
        int ans = 0;
        
        for (int i=1; i<m; i++) {
            ans = max(ans, abs(arr[i].back() - lv));
            ans = max(ans, abs(hv - arr[i][0]));
            lv = min(lv, arr[i][0]);
            hv = max(hv, arr[i].back());
        }
        
        return ans;        
    }
};