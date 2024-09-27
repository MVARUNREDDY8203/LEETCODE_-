class Solution {
public:
    bool checkValidString(string s) {
        // function<bool(string)> is_balanced = [&](string s) {
        //     int lpar = 0;
        //     for (int i=0; i<s.size(); i++) {
        //         if (s[i] == '(')
        //     }
        // };
        // function<bool(int)> bt = [&](int i) {
        //     if (i >= s.size()) {

        //     }
        // };

        int lpar = 0, star = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') lpar++;
            else if (s[i] == '*') star++;
            else {
                if (lpar == 0 && star == 0) return false;
                else if (lpar != 0) lpar--;
                else star--;
            }
        }
        int rpar = 0;
        star = 0;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] == ')') rpar++;
            else if (s[i] == '*') star++;
            else {
                if (rpar == 0 && star == 0) return false;
                else if (rpar != 0) rpar--;
                else star--;
            }
        }
        return true;
    }
};