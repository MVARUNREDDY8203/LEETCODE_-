class Solution {
public:
    int maximumInvitations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = nums.size();

        vector<vector<int>> reverse_nums(n, vector<int>(0));
        for (int i=0; i<n; i++) {
            if (i != nums[nums[i]]) reverse_nums[nums[i]].push_back(i);
        }

        vector<int> vis(n+1, 0);
        vector<int> ans(n+1, 0);

        function<int(int)> dfs = [&](int i) -> int {
            int ans = 0;

            vis[i] = 1;
            for (auto j: reverse_nums[i]) {
                ans = max(ans, dfs(j));
            }

            return 1 + ans;
        };
        function<int(int)> count_nodes_in_cycle = [&](int k) -> int {
            if (vis[k] == 3) return 0;

            vis[k] = 3;
            return 1 + count_nodes_in_cycle(nums[k]);
        };
        function<void(int)> cycle_finder = [&](int i) -> void {
            if (vis[i] == 1) {
                vis[i] = 2;
                return;
            }

            vis[i] = 1;
            cycle_finder(nums[i]);

            if (vis[i] == 2) {
                int nodes_in_cycle = count_nodes_in_cycle(i);
                ans[i] = nodes_in_cycle;
            }
        };


        int final_ans = 0;
        for (int i=0; i<n; i++) {
            if (vis[i] == 0 && i == nums[nums[i]]) {
                int left = dfs(i);
                int right = dfs(nums[i]);

                ans[i] = left + right;
                ans[nums[i]] = left + right;

                final_ans += ans[i];        // cos all the unqiue cycle-size-2 components can be placed beside each other.
            }
        }

        for (int i=0; i<n; i++) {
            if (vis[i] > 0) continue;

            cycle_finder(i);
        }

        for (int i=0; i<n; i++) {
            final_ans = max(final_ans, ans[i]);
        }

        return final_ans;
    }
};