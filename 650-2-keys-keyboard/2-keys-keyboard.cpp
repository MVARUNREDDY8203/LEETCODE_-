class Solution {
public:
    int util(int n) {
        if (n == 1) return 0;

        for (int i=2; i<=n; i++) {
            if (n % i == 0) {
                int factor2 = n / i;
                return i + util(n/i);
            }
        }
        
        return 0;
    }
    int minSteps(int n) {

        return util(n);
    }
};