class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> cache(words.size(), 0);

        string vowels = "aeiou";
        int n = words.size();
        for (int i=0; i<n; i++) {
            int cnt = 0;
            for (int j=0; j<5; j++) {
                if (words[i][0] == vowels[j]) cnt++;
                if (words[i][words[i].size()-1] == vowels[j]) cnt++;
            }
            if (cnt == 2) cache[i]++;
            if (i > 0) cache[i] += cache[i-1];
            cout<<cache[i]<<" ";
        }

        vector<int> ans;
        for (int i=0; i<queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ans.push_back(cache[r] - (l-1 >= 0 ? cache[l-1] : 0));
        }
        return ans;
    }
};