class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;
    unordered_set<int> safe;

    vector<int> ans;
    bool unsafe = false;

    bool dfs(int i, vector<vector<int>>& prerequisites) {
        if (adj[i].size() == 0) {
            if(!safe.count(i)) ans.push_back(i);
            safe.insert(i);
            return true;
        }
        if (safe.count(i)) return true;
        
        if (visited.count(i)) {
            ans.clear();
            return false;
        }
        visited.insert(i);
        
        bool flag = true;
        for (auto e: adj[i]) {
            flag &= dfs(e, prerequisites);
            if (!flag) break;
        }

        if (flag && !safe.count(i)) {
            safe.insert(i);
            ans.push_back(i);
        }
        else ans.clear();

        return flag;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        for (auto &e: prerequisites) adj[e[0]].push_back(e[1]);

        bool flag = true;
        for (int i=0; i<n; i++) {
            flag &= dfs(i, prerequisites);
            if (!flag) break;
        }
        cout<<flag<<endl;
        return ans;
    }
};