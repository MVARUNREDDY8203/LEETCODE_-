class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long int total_len = 0;
        string main_ans = "";
        for (auto i: s) {
            if (i <= '9' && i >= '0') {
                total_len *= (i - '0');
            } 
            else {
                total_len++;
            }
        }
        for (int i=s.size()-1; i>=0; i--) {
            cout<<total_len<<endl;
            if (k >= total_len) {
                k %= total_len;
                if (k == 0) {
                    while (s[i] > 'z' || s[i] < 'a') i--;
                    cout<<s[i]<<endl;
                    main_ans += s[i];
                    return main_ans;
                }
            }
            if (s[i] <= '9' && s[i] >= '0') {
                total_len /= (s[i]-'0');
            }
            else {
                total_len--;
            }
        }
        return main_ans;
    }
};