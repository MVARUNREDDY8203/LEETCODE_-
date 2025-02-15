class Solution {
public:
    bool util(int rem, string curr, string s) {
        if (rem == 0 && s == "") return true;
        if (rem < 0) return false;

        for (int j=0; j<s.size(); j++) {
            string str = s.substr(0, j+1);
            int num = stoi(str);
            if (util(rem - num, curr + str, s.substr(j+1))) return true;
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i=1; i<=n; i++) {
            if (util(i, "", to_string(i * i))) {ans += i * i; cout<<i<<endl;}
        }
        return ans;
    }
};