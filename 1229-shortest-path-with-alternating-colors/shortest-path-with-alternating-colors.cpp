class Solution {
public:
    unordered_map<int, vector<int>> red_adj;
    unordered_map<int, vector<int>> blue_adj;
    int visited_red[101];
    int visited_blue[101];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for (int i=0; i<redEdges.size(); i++) {
            red_adj[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for (int i=0; i<blueEdges.size(); i++) {
            blue_adj[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        vector<int> ans(n, -1);

        for (int i=0; i<n; i++) {
            memset(visited_red, 0, sizeof(visited_red));
            memset(visited_blue, 0, sizeof(visited_blue));

            queue<pair<pair<int, int>, int>> que;
            
            que.push({{0, 'r'}, 0});
            que.push({{0, 'b'}, 0}); 
            
            while (!que.empty()) {
                int j = que.front().first.first;
                int c = que.front().first.second;
                int dist = que.front().second;
                que.pop();
                if (j == i) {
                    ans[i] = dist;
                    break;
                }
                
                if (c == 'r') {
                    if (visited_red[j]) continue;
                    visited_red[j] = 1;

                    for (int k=0; k<red_adj[j].size(); k++) {
                        que.push({{red_adj[j][k], (int)'b'}, dist+1});
                    }
                }
                else {
                    if (visited_blue[j]) continue;
                    visited_blue[j] = 1;

                    for (int k=0; k<blue_adj[j].size(); k++) {
                        que.push({{blue_adj[j][k], (int)'r'}, dist+1});
                    }
                }
            }
        }

        return ans;
    }
};

