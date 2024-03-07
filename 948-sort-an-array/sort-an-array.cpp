class Solution {
public:
    // void mergeSort(vector<int> &nums, int l, int r) {
    //     if (r <= l) return;

    //     int mid = (r+l)/2;
    //     mergeSort(nums, l, mid);
    //     mergeSort(nums, mid+1, r);

    //     vector<int> arr3;
    //     int i=l, j=mid+1;
    //     while (i <= mid && j <= r) {
    //         arr3.emplace_back(nums[i] < nums[j] ? nums[i++] : nums[j++]);
    //     }
    //     while (i <= mid) arr3.emplace_back(nums[i++]);
    //     while (j <= r) arr3.emplace_back(nums[j++]);
        
    //     int l2 = l;
    //     for (int i=0; i<arr3.size(); i++) {
    //         nums[l2++] = arr3[i];
    //     }
    // }
    vector<int> sortArray(vector<int>& nums) {
        // mergeSort(nums, 0, nums.size()-1);
        sort(nums.begin(), nums.end());
        return nums;
    }
};
// class Solution {
// public:
//     void mergeSort(vector<int> &nums, int l, int r) {
//         if (r <= l) return;

//         int mid = (r+l)/2;
//         mergeSort(nums, l, mid);
//         mergeSort(nums, mid+1, r);

//         vector<int> arr3;
//         int i=l, j=mid+1;
//         while (i <= mid && j <= r) {
//             arr3.emplace_back(nums[i] < nums[j] ? nums[i++] : nums[j++]);
//         }
//         while (i <= mid) arr3.emplace_back(nums[i++]);
//         while (j <= r) arr3.emplace_back(nums[j++]);
        
//         int l2 = l;
//         for (int i=0; i<arr3.size(); i++) {
//             nums[l2++] = arr3[i];
//         }
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         mergeSort(nums, 0, nums.size()-1);
//         return nums;
//     }
// };