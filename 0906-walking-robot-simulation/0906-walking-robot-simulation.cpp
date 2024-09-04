class Solution {
public:
    int dir[4] = {1, 0 , 0, 0};  // N E S W
    int robotSim(vector<int>& cmds, vector<vector<int>>& obstacles) {
        int n = cmds.size(), max_dist = 0;
        int x = 0, y = 0;
        set<pair<int, int>> obs;
        for (auto i: obstacles) {
            obs.insert({i[0], i[1]});
        }

        for (int i=0; i<n; i++) {
            if (cmds[i] == -2) {
                // left
                int temp = dir[0];
                for (int i=0; i<=2; i++) dir[i] = dir[i+1];
                dir[3] = temp;
            }
            else if (cmds[i] == -1) {
                // rignt
                int temp = dir[3];
                for (int i=3; i>=1; i--) dir[i] = dir[i-1];
                dir[0] = temp;
            }
            else {
                int k = cmds[i];
                while (k > 0 && obs.find({x + dir[1] - dir[3], y + dir[0] - dir[2]}) == obs.end()) {
                    x += dir[1] - dir[3];
                    y += dir[0] - dir[2];
                    k--;
                }
            }
            cout<<dir[0]<<" "<<dir[1]<<" "<<dir[2]<<" "<<dir[3]<<endl;
            cout<<x<<" "<<y<<endl;
            max_dist = max(max_dist, (x*x)+(y*y));
        }
        return max_dist;
    }
};