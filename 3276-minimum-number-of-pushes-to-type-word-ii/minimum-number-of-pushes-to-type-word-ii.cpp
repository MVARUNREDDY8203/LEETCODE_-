class Solution {
public:
    int minimumPushes(string word) {
        int cnt[26];
        // vector<int> cnt()
        int n = word.size();
        for (int i=0; i<n; i++) {
            cnt[word[i] - 'a']++;
        }
        sort(cnt, cnt+26, greater<>());
        int ans = 0;
        for (int i=0; i<26; i++) {
            ans += cnt[i] * (i/8 + 1);
        }
        return ans;
    }
};