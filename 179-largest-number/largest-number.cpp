class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        vector<string> str_nos;
        for (auto i: nums) str_nos.push_back(to_string(i));
        
        sort(str_nos.begin(), str_nos.end(), [](const string &a, const string &b) {
            string a_b = a + b;
            string b_a = b + a;
            return a_b > b_a;
        });

        string ans = "";
        for (auto i: str_nos) ans += i;
        if (ans[0] == '0') return to_string(0);
        return ans;
    }
};