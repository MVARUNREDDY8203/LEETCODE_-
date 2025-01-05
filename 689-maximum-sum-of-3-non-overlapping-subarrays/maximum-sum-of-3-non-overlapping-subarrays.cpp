class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), curr = 0;
        for (int i=0; i<k; i++) curr += nums[i];
        vector<int> psm;
        psm.push_back(curr);
        for (int i=k; i<n; i++) {
            curr += nums[i];
            curr -= nums[i-k];
            psm.push_back(curr);
        }
        vector<pair<int, int>> left;
        left.push_back({psm[0],0});
        for (int i=1; i<psm.size(); i++) {
            if (psm[i] > left.back().first) {
                left.push_back({psm[i], i});
            }
            else left.push_back(left.back());
        }
        vector<pair<int, int>> right;
        right.push_back({psm.back(), psm.size()-1});
        for (int i=psm.size()-2; i>=0; i--) {
            if (psm[i] >= right.back().first) right.push_back({psm[i], i});
            else right.push_back(right.back());
        }
        reverse(right.begin(), right.end());
        for (auto i: psm) cout<<i<<" ";
        cout<<endl;
        for (auto i: left) cout<<i.first<<" ";
        cout<<endl;
        for (auto i: right) cout<<i.first<<" ";
        cout<<endl;

        vector<int> ans = {-1, -1, -1};
        int maxsum = 0;
        for (int i=k; i+k+k-1<n; i++) {
            int currsum = psm[i] + left[i-k].first + right[i+k].first;
            if (currsum > maxsum) {
                cout<<currsum<<" "<<maxsum<<endl;
                for (auto i: ans) cout<<i<<" ";
                cout<<endl;

                maxsum = currsum;
                ans = {left[i-k].second, i, right[i+k].second};
            }
        }

        return ans;
    }
};