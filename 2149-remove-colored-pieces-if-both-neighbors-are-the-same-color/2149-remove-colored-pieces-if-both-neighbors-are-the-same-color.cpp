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
        int a = 0;
        int b = 0;
        for (int i=2; i<s.size(); i++) {
            if (s[i] == s[i-1] && s[i-1] == s[i-2] && s[i] == 'A') a++;
            if (s[i] == s[i-1] && s[i-1] == s[i-2] && s[i] == 'B') b++;
        }
        return gameplay(a, b);
    }
};