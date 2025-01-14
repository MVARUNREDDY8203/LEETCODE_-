class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        int ua[51];
        int ub[51];
        memset(ua, 0, sizeof(ua));
        memset(ub, 0, sizeof(ub));
        
        if (A[0] == B[0]) ans[0] = 1;
        ua[A[0]]++;
        ub[B[0]]++;
        for (int i=1; i<n; i++) {
            ans[i] = ans[i-1];
            if (ua[A[i]] == 0 && ub[A[i]] > 0) {
                ans[i]++;
            }
            ua[A[i]]++;
            if (ub[B[i]] == 0 && ua[B[i]] > 0) {
                ans[i]++;
            }
            ub[B[i]]++;
        }

        return ans;
    }
};