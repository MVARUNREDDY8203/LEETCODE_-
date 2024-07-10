class Solution {
public:
    vector<int> passes = {1, 7, 30};
    int dp[365];
    int util(int i, int ticket_till, vector<int>&days, vector<int>&costs) {
        if (i >= days.size()) return 0;
        if (days[i] <= ticket_till) return util(i+1, ticket_till, days, costs);

        if (dp[i] != -1) return dp[i];

        int ticket_cost = 365001;
        for (int j=0; j<3; j++) {
            ticket_cost = min(ticket_cost, costs[j] + util(i+1, days[i] + passes[j] - 1, days, costs));
        }
        return dp[i] = ticket_cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return util(0, 0, days, costs);
    }
};