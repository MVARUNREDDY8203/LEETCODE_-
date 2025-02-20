class Solution {
public:
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};  // N E S W
    int robotSim(vector<int>& cmds, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        
        int n = cmds.size(), max_dist = 0;
        int x = 0, y = 0;
        set<pair<int, int>> obs;
        for (auto i: obstacles) {
            obs.insert({i[0], i[1]});
        }

        int ptr = 0;
        for (int i=0; i<n; i++) {
            if (cmds[i] == -2) {
                // left
                if (ptr == 0) ptr = 3;
                else ptr--;
            }
            else if (cmds[i] == -1) {
                // rignt
                ptr = (ptr+1) % 4;
            }
            else {
                int k = cmds[i];
                while (k > 0 && obs.find({x + dirs[ptr][0], y + dirs[ptr][1]}) == obs.end()) {
                    x += dirs[ptr][0];
                    y += dirs[ptr][1];
                    k--;
                }
            }
            max_dist = max(max_dist, (x*x)+(y*y));
        }
        return max_dist;
    }
};