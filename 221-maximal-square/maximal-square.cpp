class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

        int m = matrix.size(), n = matrix[0].size();
        vector<int> histogram(n, 0);
        int ans = 0;
        for (int i=0; i<m; i++) {
            // for (auto k: matrix[i]) 
            for (int j=0; j<n; j++) {
                if (matrix[i][j] - '0') histogram[j]++;
                else histogram[j] = 0;
            }
            // for (auto m: histogram) cout<<m<<" ";
            // cout<<endl;
            histogram.push_back(0);

            stack<int> stk;
            for (int j=0; j<n+1; j++) {
                while (!stk.empty() && histogram[stk.top()] > histogram[j]) {
                    int right_idx = j;
                    int curr_idx = stk.top();
                    stk.pop();
                    int left_idx = stk.empty() ? -1 : stk.top();
                    int curr_area = (right_idx - left_idx -1) >= histogram[curr_idx] ? histogram[curr_idx] * histogram[curr_idx] : 0;
                    cout<<curr_area<<endl;
                    ans = max(ans, curr_area);
                }
                stk.push(j);
            }
        }
        return ans;
    }
};