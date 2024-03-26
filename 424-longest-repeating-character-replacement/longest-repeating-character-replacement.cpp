class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, max_char_cnt = 0, ans = 0;
        int freq[26] = {0};
        for (int end = 0; end<s.size(); end++) {
            freq[s[end] - 'A']++;
            if (max_char_cnt < freq[s[end] - 'A']) max_char_cnt = freq[s[end] - 'A'];

            while ((end-start+1) - max_char_cnt > k) {
                freq[s[start] - 'A']--;
                start++;
                for (int i=0; i<26; i++) {
                    if (max_char_cnt < freq[i]) {
                        max_char_cnt = freq[i];
                    }
                }
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};