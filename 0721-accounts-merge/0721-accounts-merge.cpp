class Solution {
public:
    int parents[1001];
    unordered_map<string, int> repr;
    int find_parents(int u) {
        if (u == parents[u]) return u;
        return parents[u] = find_parents(parents[u]);
    }
    void unionSet(int u, int v) {
        int u_root = find_parents(u);
        int v_root = find_parents(v);

        if (u_root == v_root) return;
        parents[v_root] = u_root;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int m = accounts.size();
        memset(parents, -1, sizeof(parents));
        for (int i=0; i<m; i++) {
            parents[i] = i;
            int n = accounts[i].size();

            for (int j=1; j<n; j++) {
                if (repr.count(accounts[i][j])) {
                    unionSet(repr[accounts[i][j]], i);
                }
                else {
                    repr[accounts[i][j]] = parents[i];
                }
            }
        }

        vector<vector<string>> ans;
        // for (int i=0; i<m; i++) parents[i] = find_parents(i);

        for (int i=0; i<m; i++) {
            ans.push_back({accounts[i][0]});
        }
        for (auto i: repr) {
            int parent = find_parents(repr[i.first]);
            ans[parent].push_back(i.first);
        }
        vector<vector<string>> real_ans;
        for (auto i: ans) {
            if (i.size() > 1) {
                sort(i.begin()+1, i.end());
                real_ans.push_back(i);
            }
        }

        return real_ans;

    }
};