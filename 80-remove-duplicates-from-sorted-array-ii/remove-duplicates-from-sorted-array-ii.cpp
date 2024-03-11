class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0, n = nums.size(), cnt = 0, prev = nums[0];
        while (fast < n) {
            if (nums[fast] != prev) {
                cnt = 0;
                prev = nums[fast];
                continue;
            }
            cnt++;
            swap(nums[fast], nums[slow]);
            if (cnt <= 2) {
                slow++;
            }
            fast++;
        }
        return slow;
    }
};









// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int size = nums.size();
//         int l = 0, count = 1, curr =  nums[0];
//         for(int i=1; i<size; i++){
//             if(nums[i] == curr){
//                 count++;
//                 if(count<=2){
//                     swap(nums[++l], nums[i]);
//                 }
//             }else{
//                 count=1;
//                 curr = nums[i];
//                 swap(nums[++l], nums[i]);
//             }
//         }
//         return ++l;
//     }
// };