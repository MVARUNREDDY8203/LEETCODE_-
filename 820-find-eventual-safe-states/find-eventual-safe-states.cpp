class Solution {
public:
    int n = 0;
    unordered_set<int> visited;
    unordered_set<int> safe;
    unordered_set<int> unsafe;
    bool dfs(int i, vector<vector<int>>& graph) {
        if (unsafe.count(i)) return false;
        if (safe.count(i)) return true;
        
        if (visited.count(i)) return false;
        visited.insert(i);
        
        if (graph[i].size() == 0) {
            safe.insert(i);
            return true;
        }



        bool flag = true;
        for (auto &e : graph[i]) {
            flag &= dfs(e, graph);

            if (!flag) {
                unsafe.insert(i);
                break;
            }
        }
        if (flag) {
            safe.insert(i);
        }

        return flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        n = graph.size();

        for (int i=0; i<n; i++) {
            visited.clear();
            if (dfs(i, graph)) ans.push_back(i);
        }
        return ans;
    }
};