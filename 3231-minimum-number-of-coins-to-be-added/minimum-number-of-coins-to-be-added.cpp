class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int curr_max = 0;
        int additions = 0;
        int idx = 0;
        int n = coins.size();

        while (curr_max < target) {
            if (idx < n && coins[idx] <= curr_max + 1) {
                curr_max += coins[idx];
                idx++;
            } else {
                curr_max += curr_max + 1;
                additions++;
            }
        }

        return additions;
    }
};