class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) zeros++;
            else if (nums[i] == 1) ones++;
            else twos++;
        }
        for (int i=0; i<zeros; i++) nums[i] = 0;
        for (int j=zeros; j<ones+zeros; j++) nums[j] = 1;
        for (int j=ones+zeros; j<n; j++) nums[j] = 2;
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int l = 0, n = nums.size(), l2 = n-1;
//         while (l < n && l <= l2) {
//             while (l < n && l < l2 && nums[l] == 0) l++;
//             while (l2 > l && l2 >= 0 && nums[l2] != 0) l2--;
//             swap (nums[l++], nums[l2--]);
//         }

//         l = 0;
//         while (l < n && nums[l] == 0) l++;
//         l2 = n-1;
//         while (l < l2 && l < n && l2 >= 0) {
//             while (l < n && l < l2 && nums[l] == 1) l++;
//             while (l2 >= 0 && l2 >= l && nums[l2] != 1) l2--;
//             if (l < l2)swap (nums[l++], nums[l2--]);
//         }
//     }
// };
