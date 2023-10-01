class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        int i=0;
        for (i=0; i<s.size(); i++) {
            if (s[i] == ' ' && temp != "") {
                reverse(temp.begin(), temp.end());
                ans += temp + " ";
                temp = "";
            }  
            else temp += s[i];
        }
        if (temp != "") {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        return ans;
    }
};