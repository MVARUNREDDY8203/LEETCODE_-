class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        if (k == num.size()) return "0";

        stack<int> mono_stk;
        int m = 0, idx = 0;
        while (idx < num.size()) {
            while (m < k && !mono_stk.empty() && mono_stk.top() > num[idx]) {
                mono_stk.pop();
                m++;
            }
            mono_stk.push(num[idx++]);
        }
        // removing unnecessary part 
        while (mono_stk.size() > num.size() - k) {
            mono_stk.pop();
        }

        string ans = "";
        while (!mono_stk.empty()) {
            ans += mono_stk.top();
            mono_stk.pop();
        }
        reverse(ans.begin(), ans.end());
        // removing leading zeros
        string refined_ans = "";
        idx = 0;
        while (ans[idx] == '0') idx++;
        ans = ans.substr(idx, num.size()-k);
        return ans.size() == 0 ? "0" : ans;
    }
};