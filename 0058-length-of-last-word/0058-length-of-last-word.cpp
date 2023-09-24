class Solution {
public:
    int lengthOfLastWord(string s) {
        while (s.back() == ' ') s = s.substr(0, s.size()-1);

        int i = 0;
        for (int j = s.size()-1; j>=0 && s[j] != ' '; j--){
            i++;
        }
        return i;
    }
};