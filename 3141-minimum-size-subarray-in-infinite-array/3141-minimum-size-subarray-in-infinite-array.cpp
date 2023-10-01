class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long int total_sum = 0;
        int n = nums.size();
        for (auto i: nums) total_sum += i;
        
        int ans = 0;
        if ((long long)target > total_sum) {
            ans += target/total_sum * n;
            target %= total_sum;
        }
        cout<<ans;
        if (target == 0) return ans;

        vector<int> nums2(n * 2);
        for (int i=0; i<n; i++) {
            nums2[i] = nums[i];
            nums2[n+i] = nums[i];
        }
        
        
        bool found = false;
        int sub_ans = INT_MAX;
        int n2 = nums2.size();

        int start = 0;
        int end = 0;
        long long int sum = 0;

        for (start = 0; start<n2; start++) {
            sum += nums2[start];
            while (sum > target) sum -= nums2[end++];
            if (sum == (long long)target) sub_ans = min(sub_ans, start-end+1);
        }


        // for (int i=0; i<n2; i++) {
        //     long long int sum = (long long)nums2[i];
            
        //     if (sum == (long long)target) {
        //         found = true;
        //         sub_ans = min(sub_ans, 1);
        //     }
            
        //     for (int j=i+1; j<n2; j++) {
        //         sum += (long long)nums2[j];
        //         if (sum == (long long)target) {
        //             found = true;
        //             sub_ans = min(sub_ans, j-i+1);
        //         }
        //     }
        // }
        
        if (sub_ans == INT_MAX) return -1;
        return ans+sub_ans;
    }
};