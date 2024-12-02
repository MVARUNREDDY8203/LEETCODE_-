class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        int n = sentence.size(), m = sw.size();

        string curr = "";
        int idx = 1;
        for (int i=0; i<n; i++) {
            if (curr.size() == sw.size()) {
                if (curr == sw) return idx;
            }
            if (sentence[i] == ' ') curr = "", idx++;
            else curr += sentence[i];
        }
        if (curr == sw) return idx;
        return -1;
    }
};