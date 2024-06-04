class Solution {
public:
    queue<pair<string, int>> que;
    unordered_set<string> visited;
    unordered_set<string> deadends;
    int bfs(string &ans) {
        while(!que.empty()) {
            auto [str, dist] = que.front();
            que.pop();
            if (deadends.count(str) || visited.count(str)) continue;

            if (str == ans) return dist;

            visited.insert(str);
            for (int i=0; i<4; i++) {
                char org = str[i];

                str[i] = org == '9' ? '0' : org+1;
                if (!visited.count(str) && !deadends.count(str)) que.push({str, dist+1});
                str[i] = org;

                str[i] = org == '0' ? '9' : org-1;
                if (!visited.count(str) && !deadends.count(str)) que.push({str, dist+1});
                str[i] = org;
            }
        }
        return -1;
    }
    int openLock(vector<string>& dead_ends, string target) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

        que.push({"0000", 0});
        for (auto i: dead_ends) deadends.insert(i);

        return bfs(target);
    }
};