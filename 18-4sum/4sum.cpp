class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 4) return {};

        vector<vector<int>> ans;
        int i_prev = INT_MIN;
        for (int i=0; i<n-3; i++) {
            if (nums[i] == i_prev) continue;
            i_prev = nums[i];
            cout<<i<<" ";
            int j_prev = INT_MIN;
            for (int j=i+1; j<n-2; j++) {
                if (nums[j] == j_prev) continue;
                j_prev = nums[j];
                cout<<j;

                long long int l = j+1, r = n-1, sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                while (l < r) {
                    sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if (sum > target) r--;
                    else if (sum < target) l++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int last_l = nums[l], last_r = nums[r];
                        while(l<r && last_l == nums[l]) l++;    // the same element is repeating then we increment ptr
                        while(l<r && last_r == nums[r]) r--;    // the same element is repeating then we increment ptr

                        // l++;
                    }
                }
            }
            cout<<endl;
        }
        return ans;
    }
};