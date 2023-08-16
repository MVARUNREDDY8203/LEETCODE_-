class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k) {  // sliding window boundary condition check
                dq.pop_front();
            }

        
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }  
        return ans;
    }
};

// naive brute force == TLE
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     int size = nums.size();
//     if(size == 1) return nums;
//     vector<int> ans(size-k+1);
//     if(size == k){
//         for(int i=0; i<x)
//     }
//     for(int i=0; i<=size-k; i++){
//         ans[i] = nums[i];
//         for(int j=i; j<i+k; j++){
//             ans[i] = max(ans[i], nums[j]);
//         }
//     }
//     return ans;
// }