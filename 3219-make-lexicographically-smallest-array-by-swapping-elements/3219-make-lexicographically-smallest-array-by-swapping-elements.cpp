class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> n2;
        for (int i=0; i<n; i++) {
            n2.push_back({nums[i], i});
        }
        sort(n2.begin(), n2.end(), [&](pair<int, int>&a, pair<int, int>&b){
            return a.first < b.first;
        });
        vector<int> indices;
        for (auto i: n2) indices.push_back(i.second);

        int l = 0, r = 1;
        while (r < n) {
            // while (r < n && n2[r].first - n2[l].first >= limit * (r - l)) r++;
            // sort(indices.begin()+l, indices.begin()+l+(r-l));
            // l = r;

            while (r < n && n2[r].first - n2[r-1].first <= limit) r++;
            sort(indices.begin()+l, indices.begin()+l+(r-l));
            l = r;
            r++;
        }

        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) {
            ans[indices[i]] = n2[i].first;
        }

        return ans;
    }
};