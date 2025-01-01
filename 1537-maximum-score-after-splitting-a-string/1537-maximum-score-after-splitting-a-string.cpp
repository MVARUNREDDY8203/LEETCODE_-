class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for (int i=1; i<=s.size()-1; i++) {
            int temp_ans = 0;
            for (int j=0; j<i; j++) if (s[j] == '0') temp_ans++;
            for (int j=i; j<s.size(); j++) if (s[j] == '1') temp_ans++;
            ans = max(ans, temp_ans);
        }
        return ans;
    }
};