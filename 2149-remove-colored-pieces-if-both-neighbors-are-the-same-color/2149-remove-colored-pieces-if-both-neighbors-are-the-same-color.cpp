class Solution {
public:
    bool gameplay(int a, int b) {
        // alice's turn
        if (a <= 0) return false; // alice loses;
        a--;
        if (b <= 0) return true; // bob loses
        b--;
        return gameplay (a, b);
    }
    bool winnerOfGame(string s) {
        if (s.size() < 3) return false;
        string zeros = "0";
        for (int i=1; i<s.size(); i++) {
            if (s[i] == s[i-1]) zeros += zeros[i-1] + 1;
            else zeros += '0';
        }
        int a = 0;
        int b = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'A' && zeros[i] - '0' >= 2) a++;
            if (s[i] == 'B' && zeros[i] - '0' >= 2) b++;
        }
        // cout<<endl<<a<<" "<<b;
        return gameplay(a, b);
    }
};