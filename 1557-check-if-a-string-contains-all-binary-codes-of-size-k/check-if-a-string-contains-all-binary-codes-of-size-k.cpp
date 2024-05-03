class Solution {
private:
    unordered_set<string> ump;
public:
    bool hasAllCodes(string s, int k) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        
        int n = s.size();
        if (k > s.size()) return false;

        string window = "";
        for (int i=0; i<=n-k; i++) {
            window = s.substr(i, k);
            ump.insert(window);
        }
        if (ump.size() == pow(2,k)) return true;
        return false;
    }
};