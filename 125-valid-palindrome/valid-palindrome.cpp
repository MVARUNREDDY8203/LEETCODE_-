class Solution {
public:
    bool isPalindrome(string s) {
        string actual_s = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
            if ((s[i] >= 'a' && s[i] <= 'z' )|| (s[i] >= '0' && s[i] <= '9')) actual_s += s[i];
        }

        int i=0, j=actual_s.size()-1;
        while (i < j) {
            if (actual_s[i++] != actual_s[j--]) return false;
        }
        // cout<<actual_s<<endl;
        return true;
    }
};