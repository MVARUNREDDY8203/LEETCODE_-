class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int> prefix;
        prefix.push_back(arr[0]);
        for (int i=1; i<n; i++) {
            prefix.push_back(arr[i]);
            prefix[i] = prefix[i] ^ prefix[i-1];
        }
        
        vector<int> ans;
        for (int i=0; i<queries.size(); i++) {
            int min_ = queries[i][0];
            int max_ = queries[i][1];
            int curr_ans = min_ == 0 ? prefix[max_] : prefix[max_] ^ prefix[min_ - 1];
            ans.push_back(curr_ans);
        }
        
        return ans;
    }
};