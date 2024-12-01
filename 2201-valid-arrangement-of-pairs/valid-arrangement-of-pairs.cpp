class Solution {
public:
    unordered_map<int, deque<int>> graph;
    unordered_map<int, int> deg;
    vector<int> minians;
    int n = 0;
    void func(int i) {
        while (!graph[i].empty()) {
            int temp = graph[i].front();
            graph[i].pop_front();
            func(temp);
        }
        minians.push_back(i);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        n = pairs.size();
        for (int i=0; i<n; i++) {
            graph[pairs[i][0]].push_back(pairs[i][1]);
        }
        
        for (auto i: graph) {
            for (auto j: i.second) {
                deg[i.first]++;
                deg[j]--;
            }
        }

        int starter = pairs[0][0];
        for (auto i: deg) if (i.second > 0) {
            starter = i.first;
            break;
        } 


        vector<vector<int>> ans;
        func(starter);
        for (int i=minians.size()-1; i>=1; i--) {
            ans.push_back({minians[i], minians[i-1]});
        }
        return ans;
    }
};