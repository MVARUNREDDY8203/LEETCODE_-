class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> pfx_zeros(n, 0);
        vector<int> pfx_ones(n, 0);
        pfx_zeros[0] = s[0] == '0' ? 1 : 0;
        for (int i=1; i<n; i++) {
            // int add = 
            pfx_zeros[i] = pfx_zeros[i-1] + (s[i] == '0' ? 1 : 0); 
            cout<<pfx_zeros[i]<<" ";
        }

        pfx_ones[n-1] = s[n-1] == '1' ? 1 : 0;
        for (int i=n-2; i>=0; i--) {
            pfx_ones[i] = pfx_ones[i+1] + (s[i] == '1' ? 1 : 0); 
        }

        int ans = 0;
        for (int i=0; i<=n-2; i++) ans = max(ans, pfx_zeros[i] + pfx_ones[i+1]);

        return ans;
    }
};