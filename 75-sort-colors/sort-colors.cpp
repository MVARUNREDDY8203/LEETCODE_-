class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, n = nums.size(), l2 = n-1;
        while (l < n && l <= l2) {
            while (l < n && l < l2 && nums[l] == 0) l++;
            while (l2 > l && l2 >= 0 && nums[l2] != 0) l2--;
            swap (nums[l++], nums[l2--]);
        }

        l = 0;
        while (l < n && nums[l] == 0) l++;
        l2 = n-1;
        while (l < l2 && l < n && l2 >= 0) {
            while (l < n && l < l2 && nums[l] == 1) l++;
            while (l2 >= 0 && l2 >= l && nums[l2] != 1) l2--;
            if (l < l2)swap (nums[l++], nums[l2--]);
        }
    }
};
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int l = 0, l2 = 0, n = nums.size();
//         while (l < n && l2 < n && l <= l2) {
//             while (l < n && nums[l] == 0) l++;
//             int l2 = l+1;
//             while (l2 < n && nums[l2] != 0) l2++;
//             // cout<<l<<" "<<l2<<endl;
//             if (l < n && l2 < n) swap(nums[l], nums[l2]);
//         }
        
//         l = 0;
//         while (nums[l] == 0) l++;

//         l2 = l+1, n = nums.size();
//         while (l < n && l2 < n && l <= l2) {
//             // cout<<n;
//             while (l < n && nums[l] == 1) l++;
//             int l2 = l+1;
//             while (l2 < n && nums[l2] != 1) l2++;
//             cout<<l<<" "<<l2<<" "<<n<<endl;
//             if (l < n && l2 < n) swap(nums[l], nums[l2]);
//             else break;
//         }
//     }
// };