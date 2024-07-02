class Solution {
public:
    string maximumBinaryString(string binary) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int zero_cnt = 0, n = binary.size();

        int first_zero = -1, ones_cnt_after_fz = 0, ones_cnt_bef_fz = 0;
        for (int i=0; i<n; i++) {
            if (binary[i] == '0') {
                if (first_zero == -1) first_zero = i;
                zero_cnt++;
            }
            else {
                if (first_zero != -1) ones_cnt_after_fz++;
                else ones_cnt_bef_fz++;
            }
        }
        
        if (zero_cnt <= 1) return binary;

        string ans = "";
        for (int i=0; i<ones_cnt_bef_fz; i++) ans += "1";
        for (int i=0; i<zero_cnt-1; i++) ans += "1";
        ans += "0";
        for (int i=0; i<ones_cnt_after_fz; i++) ans += "1";

        return ans;
    }
};