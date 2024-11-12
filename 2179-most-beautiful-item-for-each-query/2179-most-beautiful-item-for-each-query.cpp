class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [&](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1] <= b[1];
            return a[0] < b[0];
        });
        for (int i=1; i<items.size(); i++) {
            items[i][1] = max(items[i-1][1], items[i][1]);
        }
        for (int i=0; i<queries.size(); i++) {
            vector<int> temp = {queries[i], 1000000002};
            int j = upper_bound(items.begin(), items.end(), vector<int>{queries[i], 1000000002}) - items.begin();
            // cout<<"hi"<<endl;
            j--;
            if (j >= 0) queries[i] = items[j][1];
            else queries[i] = 0;
        }
        return queries;
    }
};