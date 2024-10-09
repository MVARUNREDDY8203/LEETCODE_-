class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        function<vector<string>(string)>split_words = [&](const string &s) {
            vector<string> ans;
            string word = "";
            for (char c: s) {
                if (c == ' ') {
                    if (word.size()) ans.push_back(word);
                    word = "";
                }
                else word += c;
            }
            if (word.size()) ans.push_back(word);
            return ans;
        };

        vector<string> words1 = split_words(s1);
        vector<string> words2 = split_words(s2);

        if (words1.size() < words2.size()) swap(words1, words2);

        int l = 0;
        int n1 = words1.size()-1, n2 = words2.size()-1;

        while (l < n2+1 && words1[l] == words2[l]) l++;

        while (n2 >= 0 && words1[n1] == words2[n2]) {
            n1--;
            n2--;
        }

        return n2 < l;
    }
};