class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int steps = 0, curr_steps = 0, n = nums.size();

        stack<pair<int, int>> stk;
        stk.push({nums[n-1], 0});

        for (int i=n-2; i>=0; i--) {
            while (!stk.empty() && nums[i] > stk.top().first) {
                curr_steps = max(curr_steps+1, stk.top().second);
                stk.pop();
            }
            steps = max(steps, curr_steps);
            stk.push({nums[i], curr_steps});
            curr_steps = 0;
        }
        return steps;
    }
};


// class Solution {
// public:
//     int totalSteps(vector<int>& nums) {
//         int steps = 0;
//         bool increasing = false;
//         while (!increasing) {
//             steps++;
//             vector<int> nums2;
//             increasing = true;
//             nums2.push_back(nums[0]);
//             for (int i=1; i<nums.size(); i++) {
//                 if (nums[i-1] > nums[i]) {
//                     increasing = false;
//                     continue;
//                 }
//                 nums2.push_back(nums[i]);
//             }
//             if (increasing) return steps-1;   
//             nums = nums2;         
//         }
//         return 0;
//     }
// };