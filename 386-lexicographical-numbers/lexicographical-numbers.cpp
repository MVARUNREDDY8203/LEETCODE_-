class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
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