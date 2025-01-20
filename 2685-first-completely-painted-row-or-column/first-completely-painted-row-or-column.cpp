class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> cols(n, 0);
        vector<int> rows(m, 0);
        unordered_map<int, pair<int, int>> ump;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ump[mat[i][j]] = {i, j};
            }
        }
        for (int i=0; i<arr.size(); i++) {
            int a = ump[arr[i]].first;
            int b = ump[arr[i]].second;

            if (++rows[a] == n || ++cols[b] == m) return i;
        }
        return m * n;
    }
};