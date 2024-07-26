class Solution {
public:
    #define MOD 1000000007
    vector<int> freq;
    vector<int> last_used;
    int n = 0;
    int k = 0;
    int dp[101][101];
    int util(int i, int uq, int goal, int cnt) {
        int ans = 0;
        if (goal == 0) {
            // cout<<uq<<" "<<k<<endl;
            if (uq == n) return 1;
            return 0;
        }
        if (dp[uq][goal] != -1) return dp[uq][goal];


        for (int j=1; j<=n; j++) {
            if (freq[j] == 0) {
                freq[j]++;
                int temp = last_used[j];
                last_used[j] = cnt;

                ans = ans % MOD + util(j, uq+1, goal-1, cnt+1) % MOD;

                freq[j]--;
                last_used[j] = temp;
            }
            else {
                if (cnt - last_used[j] - 1 >= k) {
                    freq[j]++;
                    int temp = last_used[j];
                    last_used[j] = cnt;

                    ans = ans % MOD + util(j, uq, goal-1, cnt+1) % MOD;

                    freq[j]--;
                    last_used[j] = temp;
                }
            }
        } 

        return dp[uq][goal] = ans % MOD;

        // if (k > 0) {
        //     for (int j=1; j<=n; j++) {
        //         if (freq[j] == 0) {
        //             freq[j]++;
        //             ans += util(j, uq+1, goal-1, k-1);
        //             freq[j]--;
        //         }
        //     }  
            
        // } else {
        //     for (int j=1; j<=n; j++) {
        //         if (freq[j] == 0) {
        //             freq[j]++;
        //             ans += util(j, uq+1, goal-1, k-1);
        //             freq[j]--;
        //         }
        //         else {
        //             freq[j]++;
        //             ans += util(j, uq, goal-1, k-1);
        //             freq[j]--;
        //         }
        //     }
        // }

        return ans;
    }
    int numMusicPlaylists(int m, int goal, int l) {
        n = m;
        k = l;
        memset(dp, -1, sizeof(dp));
        freq.resize(n+1, 0);
        last_used.resize(n+1, 0);
        return util(0, 0, goal, k);
    }
};