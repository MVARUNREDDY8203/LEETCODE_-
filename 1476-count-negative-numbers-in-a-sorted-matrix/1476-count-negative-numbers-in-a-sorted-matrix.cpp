class Solution {
public:
    int binarySearch(vector<int> &nums, int l, int r) {
        if (l > r) return -1;
        if (r-l <= 1) return nums[l] < 0 ? l : (nums[r] < 0 ? r : -1);
        
        int mid = (l+r)/2;
        if (nums[mid] >= 0) return binarySearch(nums, mid+1, r);
        return binarySearch(nums, l, mid);
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0; i<grid.size(); i++) {
            int idx = binarySearch(grid[i], 0, grid[i].size()-1);
            if (idx == -1) continue;
            count += grid[i].size() - idx;
        }
        return count;
    }
};

// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int n = 0;
//         for (auto i: grid) {
//             for (auto j: i) {
//                 if (j < 0) n++;
//             }
//         }
//         return n;
//     }
// };