class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ans;
        int m = mat.size(), n= mat[0].size();
        for (int i=0; i<m; i++) {
            int cnt = 0;
            int j = 0;
            while (j < n && mat[i][j]) cnt += mat[i][j++];
            ans.push_back({cnt, i});
        }
        sort(ans.begin(), ans.end(), [&](pair<int, int> a, pair<int, int>b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> final;
        for (int i=0; i<k; i++) final.push_back(ans[i].second);
        return final;
    }
};