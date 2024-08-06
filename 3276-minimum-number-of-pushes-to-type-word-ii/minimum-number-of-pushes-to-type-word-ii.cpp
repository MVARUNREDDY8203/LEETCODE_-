class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int, int>> freq_map;
        for (int i=0; i<26; i++) freq_map.push_back({i, 0});
        int n = word.size();
        for (int i=0; i<n; i++) freq_map[word[i] - 'a'].second++;
        sort(freq_map.begin(), freq_map.end(), [](const pair<int, int>&a, const pair<int, int>&b){return a.second > b.second;});
        unordered_map<int, int> no_of_keystrokes;
        for (int i=0; i<26; i++) {
            no_of_keystrokes[freq_map[i].first] = i / 8 + 1;
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans += no_of_keystrokes[word[i] - 'a'];
        }
        return ans;
    }
};