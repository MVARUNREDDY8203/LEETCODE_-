class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edge_freq;

        int max_freq = 0;
        
        for (int row = 0; row < wall.size(); row++) {
            int edge_pos = 0;
            for (int brick_no = 0; brick_no < wall[row].size() - 1; brick_no++) {
                int curr_brick_len = wall[row][brick_no];
                edge_pos += curr_brick_len;
                edge_freq[edge_pos]++;
                max_freq = max(max_freq, edge_freq[edge_pos]);
            }
        }
        return wall.size() - max_freq;
    }
};


// class Solution {
// public:
//     int leastBricks(vector<vector<int>>& wall) {
//         int width = 0;
//         for (int i=0; i<wall[0].size(); i++) width += wall[0][i];

//         int ans = wall.size();
//         for (int j=width-1; j>0; j--) {
//             int count = 0;
//             for (int i=0; i<wall.size(); i++) {
//                 int col = wall[i].size() -1;
//                 if (--wall[i][col] > 0) count++;
//                 else wall[i].pop_back();
//             }
//             ans = min(ans, count);
//         }
//         return ans;
//     }
// };