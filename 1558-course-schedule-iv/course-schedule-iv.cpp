class Solution {
public:
    vector<vector<int>> adj;
    map<pair<int, int>, bool> dp;
    
    bool dfs(int src, int target) {
        if (dp.count({src, target})) return dp[{src, target}];
        if (src == target) return dp[{src, target}] = true;
        if (adj[src].size() == 0) return dp[{src, target}] = false;

        bool flag = false;
        for (auto e: adj[src]) {
            flag |= dfs(e, target);
            if (flag) {
                break;
            }
        }
        return dp[{src, target}] = flag;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prq, vector<vector<int>>& queries) {
        adj.resize(n);
        for (int i=0; i<prq.size(); i++) {
            adj[prq[i][1]].push_back(prq[i][0]);
        }
        for (auto i: adj) {
            cout<<i.size()<<endl;
        }
        vector<bool> ans;
        for (auto e: queries) {
            ans.push_back(dfs(e[1], e[0]));
        }
        return ans;
    }
};