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
        // for (int i=1; i<=n; i++) {
        //     if (util(i, "", to_string(i * i))) {ans += i * i; cout<<i<<",";}
        // }
        int cache[] = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000,30000};

        int idx = 0;
        while (n >= cache[idx]) ans += cache[idx] * cache[idx++];

        return ans;
    }
};