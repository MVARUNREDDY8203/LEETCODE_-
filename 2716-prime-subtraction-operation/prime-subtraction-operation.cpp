class Solution {
public:
    bool checkPrime(int n) {
        if (n < 2) return 0;
        for (int i=2; i <= sqrt(n); i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        
        for (int i=nums[0]-1; i>=2 && nums[0] > 2; i--) {
            if (checkPrime(i)) {
                nums[0] -= i;
                break;
            }
        }
        
        for (int i=1; i<n; i++) {
            if (nums[i] <= nums[i-1]) return 0;

            int largestPrime = 0;
            for (int j=nums[i]-1; j>=2; j--) {
                if (checkPrime(j) && nums[i] - j > nums[i-1]) {
                    largestPrime = j;
                    break;
                }
            }
            nums[i] -= largestPrime;
        }
        for (auto i: nums) cout<<i<<" ";
        return true;
    }
};