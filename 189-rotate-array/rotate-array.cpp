class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), r = n-1;
        while (l <= r) swap(nums[l++], nums[r--]);
        k = k%n;
        l = 0, r = l+k-1;
        while (l < r) swap(nums[l++], nums[r--]);
        l = k, r = n-1;
        while (l < r) swap(nums[l++], nums[r--]);
    }
};







// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         // APPROACH 3
//         k = k%nums.size();
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin()+k);
//         reverse(nums.begin()+k, nums.end());
//     }
// };
//         // // APPROACH 2
//         // int size = nums.size(),factor = size-k, temp = nums[(factor+size-1)%size];
//         // vector<int> nums2(size); 
//         // for(int i=0; i<size; i++){
//         //     nums2[(i+k)%size] = nums[i];
//         // }
//         // nums = nums2;
//         // return;
//         //////////////////////////////////////////////////////////////////////////////////
//         // // APPROACH 1
//         // int size = nums.size();
//         // for(int i=0; i<k; i++){ 
//         //     int temp = nums[size-1];
//         //     for(int j=size-1; j>0; j--){
//         //         nums[j] = nums[j-1];
//         //     }
//         //     nums[0] = temp;
//         // }return;