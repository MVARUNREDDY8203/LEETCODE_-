class Solution {
public:
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<int> ans;
        for (int i=1; i<=n; i++) {
            ans.emplace_back(i);
        }
        sort(ans.begin(), ans.end(), [&](int a, int b) {
            string m = to_string(a);
            string n = to_string(b);
            int i = 0;
            while (i < m.size() && i < n.size() && m[i] == n[i]) i++;
            if (i < m.size() && i < n.size()) {
                return m[i] < n[i];
            }
            return m.size() < n.size();
        });
        return ans;
    }
};