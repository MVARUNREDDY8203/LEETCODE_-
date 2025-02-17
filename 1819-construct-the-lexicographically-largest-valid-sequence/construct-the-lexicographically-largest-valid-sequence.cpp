class Solution {
public:
    int used[21];
    int N = 0;
    bool util(int i, vector<int> &ans) {
        if (i >= ans.size()) return true;
        if (ans[i] != 0) return util(i+1, ans);
        
        for (int num=N; num>=1; num--) {
            if (used[num]) continue;

            if (num == 1) {
                ans[i] = num;
                used[num] = 1;

                if (util(i+1, ans)) return true;

                ans[i] = 0;
                used[num] = 0;
            }
            else if (i + num < ans.size() && ans[i] == 0 && ans[i + num] == 0) {
                ans[i] = num;
                ans[i+num] = num;
                used[num] = 1;

                if (util(i+1, ans)) return true;

                ans[i] = 0;
                ans[i+num] = 0;
                used[num] = 0;
            }
        }
        for (auto i: ans) cout<<i<<" ";
        cout<<endl;
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * (n-1) + 1, 0);

        N=n;
        memset(used, 0, sizeof(used));
        util(0, ans);
        return ans;
    }
};