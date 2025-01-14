class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_set<int> ua;
        unordered_set<int> ub;
        
        if (A[0] == B[0]) ans[0] = 1;
        ua.insert(A[0]);
        ub.insert(B[0]);
        for (int i=1; i<n; i++) {
            ans[i] = ans[i-1];
            if (!ua.count(A[i]) && ub.count(A[i])) {
                cout<<A[i]<<" "<<B[i]<<" | ";
                ans[i]++;
            }
            ua.insert(A[i]);
            if (!ub.count(B[i]) && ua.count(B[i])) {
                cout<<A[i]<<" "<<B[i];
                ans[i]++;
            }
            cout<<endl;
            ub.insert(B[i]);
        }

        return ans;
    }
};