class Solution {
public:
    long long int countChildren(long long int curr, long long int n) {
        long long int cnt = 0;
        long long int nei = curr+1;
        while (curr <= n) {
            nei = min(nei, n+1);
            cnt += nei - curr;
            nei *= 10;
            curr *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        long long int curr = 1, i_th_step = 1;
        while (i_th_step < k) {
            long long int steps = countChildren(curr, n);
            if (i_th_step + steps <= k) {
                i_th_step += steps;
                curr++; // moving to the right neighbour
            }
            else {
                i_th_step++;
                curr = curr * 10;
            }
        }
        return curr;
    }
};