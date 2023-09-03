class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        int n = nums.size();
        long long int max_sum = 0;
        long long int loc_sum = 0;
        queue<long long int> que;
        unordered_map<long long int, int> mp;
        
        for(int i = 0; i<n; i++){

            loc_sum += nums[i];
            mp[nums[i]]++;
            que.push(nums[i]);

            cout<<"i = "<<i<<" loc_sum = "<<loc_sum<<" max_sum = "<<max_sum<<endl;
            if(que.size() > k){
                mp[que.front()]--;
                if(mp[que.front()] < 1) mp.erase(que.front());
                loc_sum -= que.front();
                que.pop();
            }

            if(mp.size() >= m){
                max_sum = max(max_sum, loc_sum);
            }
        }
        return max_sum;
    }
};