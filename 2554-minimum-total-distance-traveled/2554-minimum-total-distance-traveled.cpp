class Solution {
public:
    long long int memo[101][10001];
    long long util(int i, int j, vector<int>&robot, vector<int>&factory) {
        if (i >= robot.size()) return 0;
        if (j >= factory.size()) return 1e12+2;

        if (memo[i][j] != -1) return memo[i][j];

        // take
        long long int take = abs(factory[j] - robot[i]) + util(i+1, j+1, robot, factory);
        // dont take
        long long int not_take = util(i, j+1, robot, factory);

        return memo[i][j] = min(take, not_take);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [&](vector<int> a, vector<int> b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; 
        });

        int m = robot.size(), n = factory.size();

        vector<int> f2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<factory[i][1]; j++) {
                f2.push_back(factory[i][0]);
            }
        }

        memset(memo, -1, sizeof(memo));
        return util(0, 0, robot, f2);
    }
};