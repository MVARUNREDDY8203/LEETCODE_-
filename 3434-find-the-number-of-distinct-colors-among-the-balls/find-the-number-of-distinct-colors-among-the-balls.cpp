class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_c;
        unordered_map<int, int> c_count;

        vector<int> ans;
        for (auto q : queries) {
            if (ball_c.count(q[0])) {   // if a color already exists
                c_count[ball_c[q[0]]]--;    // decrement prev color
                if (c_count[ball_c[q[0]]] <= 0) c_count.erase(ball_c[q[0]]);
                ball_c[q[0]] = q[1];   // set new color
                c_count[q[1]]++;    // incr new color
            }
            else {
                ball_c[q[0]] = q[1];
                c_count[ball_c[q[0]]]++;
            }

            ans.push_back(c_count.size());
        }

        return ans;
    }
};