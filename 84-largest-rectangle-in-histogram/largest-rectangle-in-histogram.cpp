class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int ans = 0, n = heights.size();
        for (int i=0; i<n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int curr_idx = stk.top();
                int curr_height = heights[curr_idx];
                stk.pop();
                int left_idx = stk.empty() ? -1 : stk.top();
                int right_idx = i; // cos curr_idx bar will have stayed soo long in the stack becos it was smaller than every bar coming after it till ith bar
                ans = max(ans, curr_height * (right_idx - left_idx -1));
            }
            stk.push(i);
        }
        return ans;
    }
};