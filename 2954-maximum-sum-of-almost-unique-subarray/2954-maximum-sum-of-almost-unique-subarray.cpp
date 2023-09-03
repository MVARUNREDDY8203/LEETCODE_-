class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long max_sum = 0, loc_sum = 0;
        int i=0;
        unordered_map<int, int> ump;

        while(i < nums.size()){
            loc_sum += nums[i];
            ump[nums[i]]++;
            
            if(i >= k){
                loc_sum -= nums[i-k];
                ump[nums[i-k]]--;
                if(ump[nums[i-k]] < 1) ump.erase(nums[i-k]);

            }

            if(ump.size() >= m){
                max_sum = max(max_sum, loc_sum);
            }

            i++;
        }
        return max_sum;
    }
};

// class Solution {
// public:
//     long long maxSum(vector<int>& nums, int m, int k) {
     
//         int n = nums.size();
//         long long int max_sum = 0;
//         long long int loc_sum = 0;
//         queue<int> que;
//         unordered_map<int, int> mp;
        
//         for(int i = 0; i<n; i++){

//             loc_sum += nums[i];
//             mp[nums[i]]++;
//             que.push(nums[i]);

//             if(que.size() > k){
//                 mp[que.front()]--;
//                 if(mp[que.front()] < 1) mp.erase(que.front());
//                 loc_sum -= que.front();
//                 que.pop();
//             }

//             if(mp.size() >= m){
//                 max_sum = max(max_sum, loc_sum);
//             }
//         }
//         return max_sum;
//     }
// };