class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101, 0);
        int maxc = 0;
        for (int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
            maxc = max(count[nums[i]], maxc);
        }
        int ans = 0;
        // for (int i=0; i<10; i++) cout<<count[i]<<" ";
        for (int i=0; i<count.size(); i++) if (count[i] == maxc) ans += count[i];
        return ans;
    }
};