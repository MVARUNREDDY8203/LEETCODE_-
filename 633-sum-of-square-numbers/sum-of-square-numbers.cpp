class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int sqrt_c = sqrt(c), l = sqrt_c, r = 0;
        sqrt_c = (int) sqrt_c;
        while (l >= 0 && r <= sqrt_c) {
            long long int sum = l*l + r*r;
            // cout<<l<<" "<<r<<" "<<sum<<endl;
            if (sum == c) return true;
            if (sum > c) {
                l--;
            }
            else if (sum < c) {
                r++;
            }
        }
        return false;
    }
};