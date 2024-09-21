class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<int> ans;
        function<void(int)> dfs = [&](int a) -> void {
            if (a > n) return;
            ans.emplace_back(a);
            dfs(a*10);
            if ((a+1)%10 != 0) dfs(a+1);
        };
        dfs(1);
        return ans;
    }
};