class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        int ui[52];
        memset(ui, 0, sizeof(ui));

        if (ui[A[0]]++);
        if (ui[B[0]]++);
        if (ui[B[0]] == 2) ans[0]++;

        for (int i=1; i<n; i++) {
            ans[i] = ans[i-1];

            if (ui[A[i]]++);
            if (ui[A[i]] == 2) ans[i]++;

            if (ui[B[i]]++);
            if (ui[B[i]] == 2) ans[i]++;
        }

        return ans;
    }
};