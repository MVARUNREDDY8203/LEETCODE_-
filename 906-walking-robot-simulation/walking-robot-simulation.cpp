class Solution {
public:
    int dirs[4][4] = {{1, 0 , 0, 0}, {0, 1 , 0, 0}, {0, 0 , 1, 0}, {0, 0 , 0, 1}};  // N E S W
    int robotSim(vector<int>& cmds, vector<vector<int>>& obstacles) {
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
                cout<<ptr<<endl;
                while (k > 0 && obs.find({x + dirs[ptr][1] - dirs[ptr][3], y + dirs[ptr][0] - dirs[ptr][2]}) == obs.end()) {
                    x += dirs[ptr][1] - dirs[ptr][3];
                    y += dirs[ptr][0] - dirs[ptr][2];
                    k--;
                }
            }
            // cout<<dirs[ptr][0]<<" "<<dir[1]<<" "<<dir[2]<<" "<<dir[3]<<endl;
            cout<<x<<" "<<y<<endl;
            max_dist = max(max_dist, (x*x)+(y*y));
        }
        return max_dist;
    }
};