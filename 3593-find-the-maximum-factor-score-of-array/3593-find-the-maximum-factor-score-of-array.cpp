class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    
    long long maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        ll ans = nums[0];
        int n = nums.size();
        ll full_gcd = nums[0];
        ll full_lcm = nums[0];
        for (int i=1; i<n; i++) {
            full_gcd = gcd(full_gcd, nums[i]);
            full_lcm = (full_lcm * nums[i]) / (gcd(full_lcm, nums[i]));
        }
        ans = full_lcm * full_gcd;
        cout<<full_gcd<<" "<<full_lcm<<" "<<ans;
        if (n > 1) {
            for (int i=0; i<n; i++) {
                vector<int> temp;
                for (int j=0; j<n; j++) {
                    if (j != i) temp.push_back(nums[j]);
                }

                ll ans2 = temp[0];
                int m = temp.size();
                ll full_gcd2 = temp[0];
                ll full_lcm2 = temp[0];
                for (int k=1; k<m; k++) {
                    full_gcd2 = gcd(full_gcd2, temp[k]);
                    full_lcm2 = (full_lcm2 * temp[k]) / (gcd(full_lcm2, temp[k])); 
                }
                ans2 = full_lcm2 * full_gcd2;

                ans = max(ans, ans2);
            }
        }
        
        return ans;
    }
};