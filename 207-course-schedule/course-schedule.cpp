class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> adj;
    unordered_set<int> unsafe;
    unordered_set<int> safe;
    bool dfs(int i, vector<vector<int>>& prerequisites) {
        cout<<i<<" ";
        
        if (adj[i].size() == 0) return true;
        
        if (safe.count(i)) return true;
        if (unsafe.count(i)) return false;

        if (visited.count(i)) return false;
        visited.insert(i);
        

        bool flag = true;
        for (auto &j: adj[i]) {
            flag &= dfs(j, prerequisites);
            if (!flag) break;
        }

        if (flag) safe.insert(i);
        else unsafe.insert(i);

        return flag;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        for (auto &i : prerequisites) {
            adj[i[0]].push_back(i[1]);
        }

        bool flag = true;
        for (int i=0; i<n; i++) {
            visited.clear();
            flag &= dfs(i, prerequisites);
            cout<<endl;

            cout<<i<<" "<<flag<<endl;
            cout<<endl;
            if (!flag) break;
        }

        return flag;
    }
};