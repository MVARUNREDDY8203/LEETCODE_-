class Solution {
public:
    int getLucky(string s, int k) {
        string worker = "";
        for (auto i: s) {
            worker += to_string(i - 'a' + 1);
        }
        int m = 0;
        while (k) {
            m = 0;
            for (auto i: worker) {
                m += i - '0';
            }
            worker = to_string(m);
            k--;
        }
        return m;
    }
};