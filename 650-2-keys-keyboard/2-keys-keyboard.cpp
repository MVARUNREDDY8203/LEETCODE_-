class Solution {
public:
    int dp[1001];
    bool isPrime(int a) {
        if (a == 2 || a == 3) return true;
        
        if (dp[a] != -1) return dp[a];

        for (int i=2; i*i<=a; i++) {
            if (a % i == 0) return dp[a] = false;
        }
        return dp[a] = true;
    }
    int util(int n) {
        if (isPrime(n)) return n;

        for (int i=2; i<=n; i++) {
            if (isPrime(i) && n % i == 0) {
                int factor2 = n / i;
                return i + util(n/i);
            }
        }
        
        return 0;
    }
    int minSteps(int n) {
        if (n == 1) return 0;
        memset(dp, -1, sizeof(dp));

        return util(n);
        return n;
    }
};