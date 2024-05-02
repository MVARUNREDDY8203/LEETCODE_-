class Solution {
public:
    string pushDominoes(string dominoes) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n = dominoes.size();
        vector<int> prev_r(n, 0);
        int prev = -1;
        for (int i=0; i<n; i++) {
            if (dominoes[i] == 'R') {
                prev = i;
            }
            else if (dominoes[i] == 'L') {
                prev = -1;
            }
            prev_r[i] = prev;
        }

        vector<int> next_l(n, 0);
        int next = -1;
        for (int i=n-1; i>=0; i--) {
            if (dominoes[i] == 'L') {
                next = i;
            }
            else if (dominoes[i] == 'R') {
                next = -1;
            }
            next_l[i] = next;
        }

        string ans = "";
        for (int i=0; i<n; i++) {
            if (next_l[i] != -1 && prev_r[i] != -1) {
                int dist_from_l = next_l[i] - i;
                int dist_from_r = i - prev_r[i];

                ans += dist_from_l == dist_from_r ? '.' : dist_from_l > dist_from_r ? 'R' : 'L';
            }
            else if (next_l[i] != -1) {
                ans += 'L';
            }
            else if (prev_r[i] != -1) {
                ans += 'R';
            }
            else ans += '.';
        }
        return ans;
    }
};