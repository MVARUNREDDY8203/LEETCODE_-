class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        long long int sum = 0, n = chalk.size();
        for (int i=0; i<n; i++) {
            sum += chalk[i];
        }
        k = k % sum;
        for (int i=0; i<n; i++) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return -1;
    }
};