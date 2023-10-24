class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums[0] == 0) return 0;
        int n = nums.size();
        int i = 0, end = 0, farthest = 0, cnt = 0;
        for (int i=0; i<n-1; i++) {
            farthest = max(farthest, i+nums[i]);
            if (farthest >= n-1) return ++cnt;
            if (i == end) {
                cnt++;
                end = farthest;
            }
        }
        return cnt;
    }
};


// class Solution {
// public:
//     int jump(vector<int>& nums) {
        
//         int size = nums.size(), farthest = 0, current = 0, jumps = 0;

//         for(int i=0; i<size-1; i++){
//             farthest = max(farthest, nums[i]+i);
//             if(i == current){
//                 jumps++;
//                 current = farthest;
//             }
//         }

//         return jumps;
//     }
// };