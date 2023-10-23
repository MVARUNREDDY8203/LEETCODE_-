class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        for (int i=0; i<nums.size()-1 && pos >= i; i++) {
            pos = max(pos, nums[i] + i);
        }
        return pos >= nums.size()-1 ? true : false;
    }
};


// resetting min jump to 0 and traversing from behind O(n) solution
// class Solution {
// public:
//     bool canJump(vector<int> &nums) {
//         int min_jump = 0, n = nums.size();
//         for (int i=n-2; i>=0; i--) {
//             min_jump++;
//             if (nums[i] >= min_jump) min_jump = 0;
//         }
//         return min_jump == 0 ? true: false;
//     }
// };

// checking for a zero (point of problem) and checking if it can be crossed or not O(n^2)
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int size = nums.size();
//         if(size == 1) return true;
//         if(nums[0] == 0) return false;
//         for(int i=0; i<size; i++){
//             if(nums[i] == 0){
//                 int j=i-1, count =1;
//                 bool possible = false;
//                 while(j >= 0){
//                     if(nums[j]>count && i!=size-1){
//                         possible = true;
//                         break;
//                     }else if(nums[j]>=count && i == size-1){
//                         possible = true;
//                         break;
//                     }
//                     count++;
//                     j--;
//                 }
//                 if(!possible) return false;
//             }
//         }
//         return true;
//     }
// };