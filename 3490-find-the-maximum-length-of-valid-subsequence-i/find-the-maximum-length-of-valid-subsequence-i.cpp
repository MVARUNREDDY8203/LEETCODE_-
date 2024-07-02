class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, both = 1, n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i]%2 == 1) odd++;
            if (nums[i]%2 == 0) even++;
        }
        int ep = nums[0]%2 == 0 ? 1 : 0;
        for (int i=1; i<n; i++) {
            if (nums[i] % 2 == ep) {
                both++;
                ep = !ep;
            }
        }
        cout<<odd<<" "<<even<<" "<<both<<endl;
        return max(both, max(even, odd));
    }
};