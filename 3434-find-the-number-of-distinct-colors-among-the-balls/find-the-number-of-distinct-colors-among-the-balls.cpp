static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_c;
        unordered_map<int, int> c_count;

        vector<int> ans;
        int cnt = 0;
        for (auto q : queries) {
            int curr_ball = q[0];
            int new_color = q[1];

            if (ball_c.count(curr_ball)) {
                int prev_color = ball_c[curr_ball];

                c_count[prev_color]--;
                if (c_count[prev_color] == 0) cnt--;
            } 

            ball_c[curr_ball] = new_color;
            c_count[new_color]++;
            if(c_count[new_color] == 1) cnt++;

            ans.push_back(cnt);
        }

        return ans;
    }
};
