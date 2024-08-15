class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt = 0;
        for (int i=0; i<n; i++) {
            int age = ((int)details[i][11] - (int)'0') * 10 + (int)details[i][12] - (int)'0';
            if (age > 60) cnt++;
        }
        return cnt;
    }
};