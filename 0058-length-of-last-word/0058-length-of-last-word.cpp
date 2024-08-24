class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string item;
        string ans;
        while (getline(ss, item, ' ')) {
            if (item.size() > 0) {
                ans = item;
            }
        }
        return ans.size();
    }
};